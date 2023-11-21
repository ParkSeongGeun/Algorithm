#include <iostream>
#include <queue>
#include <limits.h>
#include <algorithm>
#define MAX_NODE 100001

using namespace std;

int N, S, D, F, B, K;
int MAP[MAX_NODE];
int cnt[MAX_NODE];
bool is_visited[MAX_NODE];
queue<int>q;

void bfs(int start){
    q.push(start);

    while(!q.empty()){
        int cur_node = q.front();
        int nextFront = cur_node + F;
        int nextBack = cur_node - B;
        q.pop();
        if(nextBack > 0){
            if(!is_visited[nextBack]&&MAP[nextBack]!=2){
                is_visited[nextBack] = true;
                q.push(nextBack);
                cnt[nextBack] = cnt[cur_node] + 1;
            }
        }
        if(nextFront <= N){
            if(!is_visited[nextFront]&&MAP[nextFront]!=2){
                is_visited[nextFront] = true;
                q.push(nextFront);
                cnt[nextFront] = cnt[cur_node] + 1;
            }
        }
    }
}
int main(){
    cin >> N >> S >> D >> F >> B >> K;
    MAP[D] = 1;
    for(int i=0;i<K;i++){
        int a;
        cin >> a;
        MAP[a] = 2;
    }
    cnt[D] = INT_MAX;
    bfs(S);
    if(cnt[D] == INT_MAX){
        cout << "BUG FOUND" <<"\n";
    }
    else{
        cout << cnt[D] << "\n";
    }
    return 0;
}
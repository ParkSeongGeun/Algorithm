#include <iostream>
#include <vector>
#include <stack>
#define MAX_N 100001

using namespace std;

int N;
bool visited[MAX_N];
int arr[MAX_N];

int main() {
    cin >> N;

    vector< vector<int> > MAP(N+1);

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        MAP[a].push_back(b);
        MAP[b].push_back(a);
    }

    stack<int> q;
    int start = 1;
    q.push(start);

    while(!q.empty()){
        int cur = q.top(); 
        visited[cur] = true;
        q.pop();
        for(int i = 0; i < MAP[cur].size(); i++){
            if(!visited[MAP[cur][i]] && MAP[cur][i]!=0){
                arr[MAP[cur][i]] = cur;
                q.push(MAP[cur][i]);
            }
        }
    }

    for(int i=2;i<=N;i++){
        cout << arr[i] <<"\n";
    }

    return 0;
}
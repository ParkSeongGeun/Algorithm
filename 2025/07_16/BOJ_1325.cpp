#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N, M;
int child, parent;
vector<int> v[10001];
int visited[10001];
int res[10001];

int ans, cnt;

int dfs(int parent) {
    visited[parent] = 1;
    int temp = 1;

    for(int i : v[parent]) {
        if(visited[i]) {
            continue;
        }
        temp += dfs(i);
    }

    return temp;
}

int main() {
    cin >> N >> M;

    for(int i=0;i<M;i++){
        cin >> child >> parent;

        v[parent].push_back(child);
    }

    for(int i=1;i<=N;i++) {
        memset(visited, 0, sizeof(visited));
    
        res[i] = dfs(i);
        ans = max(res[i], ans);
    }

    for(int i=1;i<=N;i++){
        if(res[i] == ans) {
            cout << i << " ";
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> vec[1001];
vector<int> res_bfs;
vector<int> res_dfs;
bool visited[1001];

int n, m, v, a, b;

void bfs(int n) {
    queue<int> q;
    q.push(n);
    visited[n] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        res_bfs.push_back(x);

        for (int i=0;i<vec[x].size();i++){
            if (!visited[vec[x][i]]) {
                q.push(vec[x][i]);
                visited[vec[x][i]] = true;
            }
        }
    }
}

void dfs(int n) {
    visited[n] = true;
    res_dfs.push_back(n);

    for(int i=0;i<vec[n].size();i++){
        if (!visited[vec[n][i]]) {
            dfs(vec[n][i]);
        }
    }
}

int main() {
    cin >> n >> m >> v;

    for(int i=0;i<m;i++){
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        sort(vec[i].begin(), vec[i].end());
    }

    dfs(v);
    memset(visited, false, sizeof(visited));
    bfs(v);

    for(int i : res_dfs) {
        cout << i << " ";
    }
    cout << "\n";
    for(int i : res_bfs) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool visited[1001];
vector<int> v[1001];

void dfs(int num) {
    // cout << "current: " << num << "\n";
    if (visited[num]) {
        return;
    }

    visited[num] = true;

    for(int i=0;i<v[num].size();i++){
        if (visited[v[num][i]]) {
            continue;
        }

        dfs(v[num][i]);
    }

    return;
}

int main() {
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i=1;i<=n;i++){
        sort(v[i].begin(), v[i].end());
    }

    int ans = 0;
    for(int i=1;i<=n;i++){
        if (!visited[i]) {
            dfs(i);
            ans++;
        }
    }

    cout << ans << "\n";
    return 0;
}
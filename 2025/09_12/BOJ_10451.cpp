#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int t;
int n;
vector<int> v[1001];
bool visited[1001];

void dfs(int num) {
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
    cin >> t;
    for(int i=0;i<t;i++){
        memset(visited, false, sizeof(visited));
        for(int i=0;i<1001;i++){
            v[i].clear();
        }

        cin >> n;
        for(int i=1;i<=n;i++){
            int a;
            cin >> a;
            v[i].push_back(a);
            v[a].push_back(i);
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            if (!visited[i]) {
                dfs(i);
                ans++;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
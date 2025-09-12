#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int k;
vector<int> v[20001];
int possible; // p 대신 더 명확한 이름으로 변경
int visited[20001];

void dfs(int num, int c) {
    if (visited[num]) {
        if (visited[num] != c) {
            possible = 0;
        }
        return;
    }

    visited[num] = c;
    for(auto &node : v[num]) { // p 대신 node로 변경
        dfs(node, 3 - c);
    }
}

int main() {
    cin >> k;

    for(int tc = 0; tc < k; tc++) { // i 대신 tc로 변경 (아래 i와 충돌 방지)
        possible = 1;
        
        // vector 배열 초기화
        for(int i = 0; i < 20001; i++) {
            v[i].clear();
        }
        memset(visited, 0, sizeof(visited)); // false 대신 0
        
        int a, b, x, y;
        cin >> a >> b;
        for(int i = 0; i < b; i++) {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        for(int i = 1; i <= a; i++) { // x 대신 a (노드 개수)
            if (!visited[i]) { // x 대신 i
                dfs(i, 1);
            }
        }

        if (possible == 1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
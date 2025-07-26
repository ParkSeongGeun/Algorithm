#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N, L, R, ans;
int m[51][51];
bool visited[51][51];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

vector<pair<int, int>> union_pair;
int sum;

void dfs(int y, int x) {
    visited[y][x] = true;
    // dfs가 된다 -> 일단 연합에 넣고 -> 계속 추가... 이후 2개 이상 연합 발생시 확인을 위함.
    union_pair.push_back({y, x});
    sum += m[y][x];

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
            continue;
        }

        if (visited[ny][nx]) {
            continue;
        }

        int diff = abs(m[y][x] - m[ny][nx]);

        if (diff >= L && diff <= R) {
            dfs(ny, nx);
        }
    }
}

bool simulation() {
    memset(visited, false, sizeof(visited));
    bool moved = false;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                // 매 dfs 전에 초기화
                union_pair.clear();
                sum = 0;
                
                dfs(i, j);
                
                if (union_pair.size() > 1) {
                    moved = true;
                    int avg = sum / union_pair.size();
                    
                    for(auto p : union_pair) {
                        m[p.first][p.second] = avg;
                    }
                }
            }
        }
    }

    return moved;
}

int main() {
    cin >> N >> L >> R;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> m[i][j];
        }
    }
    
    while(simulation()) {
        ans++;
    }

    cout << ans << endl;

    return 0;
}
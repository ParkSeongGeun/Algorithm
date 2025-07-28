#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int R, C;
char m[1001][1001];
int f_time[1001][1001];  // 불 -> 각 위치에 도달하는 시간
int j_time[1001][1001];  // 지훈 -> 각 위치에 도달하는 시간
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs_f() {
    queue<pair<int, int>> q;
    
    // 초기화
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            f_time[i][j] = -1;
        }
    }
    
    // 모든 불의 초기 위치를 큐에 추가
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(m[i][j] == 'F') {
                q.push({i, j});
                f_time[i][j] = 0;
            }
        }
    }
    
    // BFS로 불이 퍼지는 시간 계산
    while(!q.empty()) {
        pair<int, int> p = q.front();
        int y = p.first;
        int x = p.second;

        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if(ny < 0 || ny >= R || nx < 0 || nx >= C) {
                continue;
            }
            
            // 벽이거나 이미 불이 도달했으면 스킵
            if(m[ny][nx] == '#' || f_time[ny][nx] != -1) {
                continue;
            }

            f_time[ny][nx] = f_time[y][x] + 1;
            q.push({ny, nx});
        }
    }
}

int bfs_j() {
    queue<pair<int, int>> q;
    
    // 초기화
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            j_time[i][j] = -1;
        }
    }
    
    // 지훈이 초기 위치 찾기
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(m[i][j] == 'J') {
                q.push({i, j});
                j_time[i][j] = 0;
                break;
            }
        }
    }
    
    while(!q.empty()) {
        pair<int, int> p = q.front();
        int y = p.first;
        int x = p.second;

        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 경계를 벗어나면 리턴
            if(ny < 0 || ny >= R || nx < 0 || nx >= C) {
                return j_time[y][x] + 1;
            }
            
            // 벽이거나 이미 방문했으면 스킵
            if(m[ny][nx] == '#' || j_time[ny][nx] != -1) {
                continue;
            }

            // 불이 이미 도달 or 지훈 도착 때 - 같은 시간에 불이 도달하면 거르기
            if(f_time[ny][nx] != -1 && f_time[ny][nx] <= j_time[y][x] + 1) {
                continue;
            }

            j_time[ny][nx] = j_time[y][x] + 1;
            q.push({ny, nx});
        }
    }
    
    return -1; // impossible
}

int main() {
    cin >> R >> C;
    
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> m[i][j];
        }
    }
    
    // 불이 퍼지는 시간
    bfs_f();
    
    // 지훈 계산
    int result = bfs_j();
    
    if(result == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}
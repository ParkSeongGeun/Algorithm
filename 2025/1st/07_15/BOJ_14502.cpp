#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, cnt;
int res = -2147483647;
int m[10][10];
int copy_m[10][10];
int visited[10][10];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int ny, nx;

vector<pair<int, int>> v;

// 벽은 꼭 3개

void dfs(int y, int x) {
    copy_m[y][x] = 2;
    visited[y][x] = true;

    for(int i=0;i<4;i++){
        ny = y + dy[i];
        nx = x + dx[i];

        if (ny<0||ny>=N||nx<0||nx>=M) {
            continue;
        }

        if (copy_m[ny][nx] == 0 && !visited[ny][nx]) {
            dfs(ny, nx);
        }
    }

    return;
}

int main() {
    cin  >> N >> M;
    for(int i=0;i<N;i++ ){
        for (int j=0;j<M;j++){
            cin >> m[i][j];
            copy_m[i][j] = m[i][j];
            if (m[i][j] == 0) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
                cnt = 0;
                memcpy(copy_m, m, sizeof(m));
                memset(visited, false, sizeof(visited));

                copy_m[v[k].first][v[k].second] = 1;
                copy_m[v[j].first][v[j].second] = 1;
                copy_m[v[i].first][v[i].second] = 1;

                for(int h=0;h<N;h++){
                    for(int l = 0;l<M;l++){
                        if(copy_m[h][l] == 2 && !visited[h][l]) {
                            dfs(h, l);
                        }
                    }
                }

                // 결과출력용
                for(int h=0;h<N;h++){
                    for(int l=0;l<M;l++){
                        //cout << copy_m[h][l] << " ";
                        if (copy_m[h][l] == 0) {
                            cnt++;
                        }
                    }
                    //cout << "\n";
                }

                // for(int h=0;h<N;h++){
                //     for(int l=0;l<M;l++){
                //         cout << visited[h][l] << " ";
                //     }
                //     cout << "\n";
                // }

                // cout << "cnt: " << cnt << "\n";
                if (res < cnt) {
                    res = cnt;
                }
            }
        }
    }

    cout << res << "\n";
    return 0;
}
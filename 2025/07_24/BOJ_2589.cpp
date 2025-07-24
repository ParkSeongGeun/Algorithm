#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <queue>

using namespace std;

int visited[51][51];
char m[51][51];
int a, b;
int ans, cnt;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void print() {
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout << visited[i][j] <<" ";
        }
        cout << "\n";
    }
}
void go(int y, int x) {
    visited[y][x] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    
    while(!q.empty()) {
        // print();
        // cout << "\n===============\n";
        pair<int, int> c = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int ny = c.first + dy[i];
            int nx = c.second + dx[i];

            if(ny<0||ny>=a||nx<0||nx>=b||visited[ny][nx]||(m[ny][nx]=='W')) {
                continue;
            }

            q.push(make_pair(ny, nx));
            visited[ny][nx] = visited[c.first][c.second] + 1;
        }
    }
}

int main() {
    cin >> a >> b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> m[i][j];
        }
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            memset(visited, 0, sizeof(visited));
            if(m[i][j]=='L'){
                go(i, j);
            }

            for(int z = 0;z<a;z++){
                for(int q=0;q<b;q++){
                    if (ans < visited[z][q] - 1){
                        ans = visited[z][q] - 1;
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int res = 1;
int MAP[101][101];
int visited[101][101];
int dist[101][101];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
queue< pair<int, int> > q;

int BFS(int start_y, int start_x){
    visited[start_y][start_x] = 1;
    q.push(make_pair(start_y, start_x));
    dist[start_y][start_x]++;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        cout << "y, x 좌표 -> " << y << " " << x << "\n";
        q.pop();
        for(int i=0;i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<=0||nx<=0||ny>N||nx>M||visited[ny][nx]!=0||MAP[ny][nx]==0){
                continue;
            }
            else{
                visited[ny][nx] = 1;
                q.push(make_pair(ny, nx));
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            char c;
            cin >> c;
            MAP[i][j] = c-'0';
        }
    }
    BFS(1,1);
    cout << dist[N][M] << "\n";
    return 0;
}
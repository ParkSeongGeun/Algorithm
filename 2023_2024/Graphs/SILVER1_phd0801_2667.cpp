#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
int MAP[26][26];
bool visited[26][26];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
queue< pair<int, int> > q;
vector<int> result;
int building;

void bfs(int y, int x){
    q.push(make_pair(y, x));
    visited[y][x]=true;
    building++;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i=0;i<4;i++) {
            int ny = a + dy[i];
            int nx = b + dx[i];
            if(0<nx && 0<ny && nx <= N && ny <= N && visited[ny][nx]==false && MAP[ny][nx]==1) {
                q.push(make_pair(ny, nx));
                visited[ny][nx]=true;
                building++;
            }
        }
    }
}
int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            char a;
            cin >> a;
            MAP[i][j] = a-'0';
        }
    }
    for (int i=1; i<= N;i++) {
        for(int j=1;j<=N;j++) {
            if(MAP[i][j]==1 && visited[i][j]==false) {
                building = 0;
                bfs(i,j);
                result.push_back(building);
            }
        }
    }
    cout << result.size() << "\n";
    sort(result.begin(), result.end());
    for(int i=0;i<result.size();i++){
        cout << result[i] << "\n";
    }
    return 0;
}
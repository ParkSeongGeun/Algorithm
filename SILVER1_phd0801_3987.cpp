#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
char MAP[501][501];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1, 0, 1, 0}; // 방향은 U, R, D, L 순
char direction[4] = {'U', 'R', 'D', 'L'};
int ans_dir;
int res;
bool voyager;

void dfs(int y, int x, int start_dir){
    int cur = 1;
    int cur_x = x, cur_y = y;
    int dir = start_dir;

    while(1){
        cur_x = cur_x + dx[dir];
        cur_y = cur_y + dy[dir];

        if(cur_x<=0||cur_y<=0||cur_x>M||cur_y>N||MAP[cur_y][cur_x]=='C'){
            if(res<cur){
                res = cur;
                ans_dir = start_dir;
            }
            return;
        }

        if (cur_x==x&&cur_y==y&&dir==start_dir){
            ans_dir = start_dir;
            voyager = true;
            return ;
        }

        if(MAP[cur_y][cur_x] == '/'){
            dir = 1 ^ dir;
        }
        else if(MAP[cur_y][cur_x] == '\\'){
            dir = 3 - dir;
        }
        cur++;
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N >> M;
    for(int i=1; i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> MAP[i][j];
        }
    }
    int y, x;
    cin >> y >> x;
    for(int i = 0;i<4;i++){
        if(!voyager){
            dfs(y, x, i);
        }
    }
    cout << direction[ans_dir] << "\n";
    if(voyager){
        cout << "Voyager" <<"\n";
    }
    else{
        cout << res << "\n";
    }
}
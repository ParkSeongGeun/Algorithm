#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int N, cnt;
int res = 2e9;
int MAP[11][11];
int visited[11];
int start_position;

void go(int pos, int cnt, int sum) {
    if(cnt == N){
        if(MAP[pos][start_position] > 0){
            res = res > (sum + MAP[pos][start_position]) ? sum + MAP[pos][start_position] : res;
        }
        return;
    }
    for(int i=1;i<=N;i++){
        if(MAP[pos][i] == 0){
            continue;
        }
        if(visited[i] == true){
            continue;
        }
        visited[i] = true;
        go(i, cnt + 1, sum + MAP[pos][i]);
        visited[i] = false;
    }
}

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> MAP[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        start_position = i;
        visited[i] = true;
        go(i, 1, 0);
        visited[i] = false;
    }
    cout << res << "\n";
    return 0;
}
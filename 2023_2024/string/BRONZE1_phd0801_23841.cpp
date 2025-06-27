#include <iostream>

using namespace std;

int N, M;
char map[51][51];

int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> map[i][j];
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M/2;j++){
            if(map[i][j] != '.'){
                map[i][M-j+1] = map[i][j];
            }
        }
        for(int j=M/2+1;j<=M;j++){
            if(map[i][j] != '.'){
                map[i][M-j+1] = map[i][j]; 
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cout << map[i][j];
        }
        cout << "\n";
    }
    return 0;
}
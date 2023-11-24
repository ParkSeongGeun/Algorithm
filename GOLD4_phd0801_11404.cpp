#include <iostream>
#define INF 10000000

using namespace std;

int n, m;
int MAP[101][101];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n;
    cin >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i==j){
                MAP[i][j] = 0;
            }
            else{
                MAP[i][j] = INF;
            }
        }
    }
    for(int i = 1; i <= m;i++){
        int y, x, cnt;
        cin >> y >> x >> cnt;
        MAP[y][x] = min(MAP[y][x], cnt);
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            if(i==k){
                continue;
            }
            for(int j = 1; j<= n; j++){
                if(j==i||j==k){
                    continue;
                }
                MAP[i][j] = min(MAP[i][k] + MAP[k][j], MAP[i][j]);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(MAP[i][j] == INF){
                cout << "0" << " ";
            }
            else{
                cout << MAP[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
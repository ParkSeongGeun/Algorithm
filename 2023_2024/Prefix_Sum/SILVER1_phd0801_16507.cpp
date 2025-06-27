#include <iostream>
#include <algorithm>

using namespace std;

int R, C, Q;
long long dp[1001][1001];
long long arr[1001][1001];

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> R >> C >> Q;
    for(int i=1;i<=R;i++){
        int index = 0;
        for(int j=1;j<=C;j++){
            int num;
            cin >> num;
            index += num;
            arr[i][j] = num;
            dp[i][j] = index;
        }
    }

    for(int i=0;i<Q;i++){
        int y1,y2,x1,x2;
        int res = 0;  
        cin >> y1 >> x1 >> y2 >> x2;
        for(int j=y1;j<=y2;j++){
            res += dp[j][x2]-dp[j][x1-1];
        }
        cout << res / ((y2-y1+1)*(x2-x1+1)) << "\n";
    }
    return 0;
}
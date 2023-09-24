#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,K;
int W[101], V[101];
int dp[101][100001];

void    go()
{
    for(int i=1;i<=N;i++) // i = 들어간 짐의 개수
    {
        for(int j=1;j<=K;j++) // j = 무게
        {
            if(j-W[i]>=0)
            {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}
int main(){
    cin >> N >> K;
    for(int i=1;i<=N;i++)
    {
        cin >> W[i] >> V[i];
    }
    go();
    cout << dp[N][K] << "\n";
    return 0;
}
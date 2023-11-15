#include <iostream>
#include <algorithm>
#include <climits>
 
using namespace std;

int S[502][502];
int P[502][502];
int minCost[502][502];

void print_result(int i, int j){
    if(i==j){
        printf("(A + %d)", i);
    }
    else{
        printf("(");
        print_result(i, S[i][j]);
        print_result(S[i][j]+1, j);
        printf(")");
    }
}

int main()
{
    int N;
    cin >> N;
 
    for (int i = 1; i <= N; i++)
    {
        cin >> P[i][0];
        cin >> P[i][1];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j){
                minCost[i][j]=0;
            }
        }
    }
    for (int l = 1; l < N; l++)
    {
        for (int i = 1; i <= N - l; i++)
        {
            int j = i + l;
            minCost[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int q = minCost[i][k] + minCost[k + 1][j] + P[i][0] * P[k][1] * P[j][1];
                if(q < minCost[i][j]){
                    minCost[i][j] = q;
                    S[i][j] = k;
                }
            }
        }
    }
    // cout << minCost[1][N] << "\n";
    // for(int i=1;i<=N;i++){
    //     for(int j=1;j<=N;j++){
    //         cout << minCost[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    print_result(1, N);
}
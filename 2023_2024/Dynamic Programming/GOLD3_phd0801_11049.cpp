#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

int N, r, c;

long long arr[501][501];
long long cnt[501];

int main(){
    cin >> N;
    int idx=0;
    for(int i=1;i<=N*2;i++){
        long long a;
        cin >> a;
        if(i==1||i%2==0){
            cnt[idx]=a;
            idx++;
        }
    }
    for(int i=1;i<=N;i++){
        arr[i][i] = 0;
    }
    for(int L=1;L<=N-1;L++){
        for(int i=1;i<=N-L;i++){
            int j = i + L;
            arr[i][j] = 2147483648;
            for(int k=i;k<=j-1;k++){
                long long temp = arr[i][k] + arr[k+1][j] + cnt[i-1]*cnt[k]*cnt[j];
                if(temp < arr[i][j]){
                    arr[i][j] = temp;
                }
            }
        }
    }
    cout << arr[1][N] << "\n";
    return 0;
}
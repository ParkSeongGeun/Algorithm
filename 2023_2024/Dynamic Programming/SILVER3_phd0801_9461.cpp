#include <iostream>
#include <algorithm>

using namespace std;

int T;
long long dp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

void go(){
    for(int i=11;i<=100;i++){
        dp[i] = dp[i-1] + dp[i-5];
    }
}

int main(){
    cin >> T;
    int input_num;
    go();
    for(int i=0;i<T;i++){
        cin >> input_num;
        cout << dp[input_num] << "\n";
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dp[100] = {0,1};

int fibonacci(int n) {
    if (n == 0) {
        return dp[0];
    } 
    if (n == 1) {
        return dp[1];
    }
    if (dp[n] > 0){
        return dp[n];
    }
    dp[n] = fibonacci(n-2)+fibonacci(n-1);
    return dp[n];
}

int main(){
    cin >> N;
    int input_num;
    for(int i=0;i<N;i++){
        cin >> input_num;
        if(input_num == 0){
            cout << 1 << " " << 0 << "\n";
        }
        else{
            fibonacci(input_num);
            cout << fibonacci(input_num-1) << " " << fibonacci(input_num) << "\n";
        }
    }
    return 0; 
}
#include <iostream>
#include <math.h>

using namespace std;

int N, K;
int res = 1;
int mod = 1;

int main(){
    cin >> N >> K;
    for(int i=1;i<=K;i++){
        mod *= i;
    }
    int i=0;
    while(i<K){
        res *= N;
        N--;
        i++;
    }
    cout << res/mod << "\n";
    return 0;
}
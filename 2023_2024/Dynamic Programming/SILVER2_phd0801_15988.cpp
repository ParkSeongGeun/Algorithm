#include <iostream>
#include <vector>
#define LL unsigned long long
#define mod 1000000009

using namespace std;

int T, cnt;
LL v[1000001];

LL go (int start){
    if(v[start] > 0){
        return v[start];
    }
    v[start] = (go(start-3) % mod + go(start-2) % mod + go(start-1) % mod) % mod;
    return v[start];
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> T;
    v[0] = 1;
    v[1] = 1;
    v[2] = 2;
    v[3] = 4;
    for(int i=0;i<T;i++){
        cin >> cnt;
        cout << go(cnt) << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int N, K;
string a, b;

int main(){
    cin >> N;
    while(N--){
        map<string, int> _map;
        cin >> K;
        for(int i=0; i<K; i++){
            cin >> a >> b;
            _map[b]++;
        }
        int ret = 1;
        // a + b + ab = (a+1)*(b+1)-1
        for(auto c : _map){
            ret *= (c.second + 1);
        }
        ret--;
        cout << ret << "\n";
    }
    return 0;
}
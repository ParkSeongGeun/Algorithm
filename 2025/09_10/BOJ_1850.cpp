#include <iostream>

using namespace std;

typedef unsigned long long ll;

ll n;

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }

    return gcd(b, a % b);
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);

    ll a, b;
    cin >> a >> b;

    for(int i=0;i<gcd(a, b);i++){
        cout << 1;
    }
    cout << "\n";
    return 0;
}
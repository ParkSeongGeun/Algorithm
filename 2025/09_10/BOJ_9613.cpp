#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;

ll gcd(ll a, ll b) {
    if (a % b == 0){
        return b;
    }

    return gcd(b, a%b);
}

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n;

    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        vector<ll> v(m);
        for(int j=0;j<m;j++){
            cin >> v[j];
        }
        sort(v.begin(), v.end());

        ll res=0;
        for(int j=0;j<m;j++){
            for(int k=j+1;k<m;k++){
                res += gcd(v[j], v[k]);
            }
        }
        cout << res << "\n";
    }
    return 0;
}
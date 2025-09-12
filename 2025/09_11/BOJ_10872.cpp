#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ll;

int n;

int main() {
    cin >> n;
    
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }

    ll res = 1;
    for(int i=1;i<=n;i++){
        res *= i;
    }

    cout << res << "\n";
    return 0;
}
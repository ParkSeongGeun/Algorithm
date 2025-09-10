#include <iostream>

using namespace std;

typedef long long ll;

ll n;
string res = "";

int main() {
    cin >> n;
    
    if (n==0) {
        cout << "0" <<"\n";
        return 0;
    }

    while(n != 0){
        if (n % -2 == 0){
            res = "0" + res;
            n /= -2;
        }
        else {
            res = "1" + res;
            n = (n-1) / -2;
        }
    }
    cout << res << "\n";
    return 0;
}
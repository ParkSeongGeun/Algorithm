#include <iostream>

using namespace std;

int n;

int gcd(int a, int b) {
    if (a % b == 0) {
        return b;
    }

    return gcd(b, a % b);
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        if (a < b) {
            int cnt = a;
            a = b;
            b = cnt;
        }
        cout << a * b / gcd(a, b) << "\n";
    }
}
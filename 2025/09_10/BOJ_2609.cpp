#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    while(a % b != 0) {
        int cnt = b;
        // cout << a << ", " << b << "\n";
        b = a % b;
        a = cnt;
    }
    return b;
}

int main() {
    int a, b;
    cin >> a >> b;
    int cnt = a;
    if (a < b) {
        a = b;
        b = cnt;
    }

    cout << gcd(a, b) << "\n";
    cout << a * b / gcd(a, b) << "\n";
    return 0;
}
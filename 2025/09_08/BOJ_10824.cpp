#include <iostream>
#include <cstring>

using namespace std;

int main() {
    string a, b, c, d;

    cin >> a >> b >> c >> d;

    string x = a + b;
    string y = c + d;

    unsigned long long res1 = stoull(x);
    unsigned long long res2 = stoull(y);

    cout << res1 + res2 << "\n";
    return 0;
}
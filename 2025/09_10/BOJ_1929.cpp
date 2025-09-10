#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// n까지의 수중, 소수들을 출력하는 알고리즘
void isPrime(vector<bool>& v, int n) {

    for(int i=2;i<=n;i++){
        v[i] = true;
    }

    for(int i=2;i<=n;i++){
        if (v[i]) {
            for(int j=i*2;j<=n;j+=i) {
                v[j] = false;
            }
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    vector<bool> v(b + 1);

    isPrime(v, b);

    for(int i=a;i<=b;i++){
        if (v[i]) {
            cout << i << "\n";
        }
    }
    return 0;
}
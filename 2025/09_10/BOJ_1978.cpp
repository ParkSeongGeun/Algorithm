#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

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
    cin >> n;

    vector<int> input(n);

    for(int i=0;i<n;i++){
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    vector<bool> v(input[n-1] + 1);

    isPrime(v, input[n-1]);

    // for(int i:v) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    int res = 0;
    for(int i=0;i<n;i++){
        if (v[input[i]]) {
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
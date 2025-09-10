#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100001];
int input[100001];

void checkPrime(vector<bool>& v, int n) {
    for(int i=3;i<=n;i++){
        v[i] = true;
    }

    for(int i=3;i<=n;i++){
        if (v[i]) {
            for(int j=i*2;j<=n;j+=i) {
                v[j] = false;
            }
        }
    }
}

int main() {
    int a;
    int i = 0;
    while(cin >> a && a != 0) {
        arr[i] = a;
        input[i] = a;
        i++;
    }

    sort(arr, arr + i);

    vector<bool> v(arr[i-1] + 1);
    checkPrime(v, arr[i-1]);

    for(int j = 0; j<i;j++){
        for(int k = 3; k<= arr[i-1]; k++) {
            if (v[k]) {
                if (v[input[j]-k]) {
                    cout << input[j] << " = " << k << " + " << input[j] - k << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
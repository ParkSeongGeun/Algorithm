#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, b;

char c[36];

int main() {
    cin >> n >> b;

    for(int i=0;i<10;i++){
        c[i] = '0'+i;
    }
    for(int i=0;i<26;i++){
        c[10+i] = 'A' + i;
    }

    vector<int> v;

    while(1) {
        int mod = n % b;
        v.push_back(mod);
        n = n / b;
        if (n == 0){
            break;
        }
    }

    reverse(v.begin(), v.end());

    for(int i:v) {
        cout << c[i];
    }
    cout << "\n";

    return 0;
}
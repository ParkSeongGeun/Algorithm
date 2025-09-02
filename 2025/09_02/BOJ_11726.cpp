#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int input;
vector<int> v(1001);

int go(int num) {
    // cout << "num: " << num << "\n";
    if(v[num] != 0) {
        return v[num];
    }

    if(num == 1) {
        return v[num] = 1;
    }

    if(num == 2) {
        return v[num] = 2;
    }

    // v[9] = go(7) + go(8);
    // v[7] = go(5) + go(6);
    // v[8] = go(6) + go(7);
    v[num] = (go(num-2) + go(num-1)) % 10007;

    return v[num];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> input;
    cout << go(input) << "\n";

    return 0;
}
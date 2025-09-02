#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a;
vector<int> v(101);

int go(int num) {
    if (v[num] != 0) {
        return v[num];
    }
    
    if (num==1) {
        return v[num] = 9;
    }

    if (num==2) {
        return v[num] = 17;
    }

    return v[num] = (go(num - 1) + go(num - 2)) % 1,000,000,000;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a;
    cout << go(a) << "\n";
}
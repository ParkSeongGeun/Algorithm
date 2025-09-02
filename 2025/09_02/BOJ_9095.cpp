#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(11);

int go(int num) {
    if (v[num] != 0) {
        return v[num];
    }

    if (num==1) {
        return v[num] = 1;
    }

    if (num==2) {
        return v[num] = 2;
    }

    if (num==3) {
        return v[num] = 4;
    }

    return v[num] = go(num-1) + go(num-2) + go(num-3);
}

int main() {
    int a, b;
    cin >> a;
    for(int i=0;i<a;i++){
        cin >> b;
        cout << go(b) << "\n";
    }
    return 0;
}
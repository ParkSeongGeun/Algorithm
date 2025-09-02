#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int a;
int ans = INT_MAX;

vector<int> v(1000000);

void go(int num, int cnt) {
    // cout << "num: " << num << ", cnt: " << cnt << "\n";
    if (num == 1) {
        if (ans > cnt) {
            ans = cnt;
        }
        return;
    }

    if ((v[num] != 0 && v[num] < cnt) || num <= 0) {
        return;
    }

    v[num] = cnt;

    if (num % 3 == 0) {
        go(num / 3, cnt + 1);
    }
    if (num % 2 == 0) {
        go(num / 2, cnt + 1);
    }
    go(num-1, cnt + 1);
}


int main() {
    cin >> a;
    go(a, 0);
    cout << ans << "\n";
    return 0;
}
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string ans[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    int cnt = 0;

    // [1, 1] -> [3, 29]
    for(int i = 1; i < a; i++ ){
        if (i == 2) {
            cnt += 28;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            cnt += 30;
        } else {
            cnt += 31;
        }
    }

    cnt += b - 1;

    int t = cnt % 7;

    cout << ans[t] << "\n";

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n;
pair<int, int> q;

void isTwoOrFive(int n) {
    vector<int> v;

    int temp = 2;
    while(n != 1) {
        if (n % temp == 0) {
            v.push_back(temp);
            n = n / temp;
            temp = 2;
        } else {
            temp++;
        }
    }

    for(int i : v) {
        if (i == 2) {
            q.first++;
        }
        else if (i == 5) {
            q.second++;
        }
    }

    return;
}

int main() {
    cin >> n;

    if (n == 0) {
        cout << 0 << "\n";
        return 0;
    }

    for(int i=1;i<=n;i++){
        isTwoOrFive(i);
    }

    cout << min(q.first, q.second) << "\n";
    return 0;
}
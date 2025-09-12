#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {
    cin >> n;

    vector<int> v;

    if (n == 1) {
        return 0;
    }

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

    for(auto i : v) {
        cout << i << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;

int main() {
    cin >> n >> k;

    vector<int> v(n);
    v[0] = 0;
    for(int i=1;i<=n;i++){
        v[i-1] = i;
    }

    int idx = 0;
    cout << "<";
    while(v.size() > 1) {
        idx = (idx + k - 1) % v.size();
        cout << v[idx] << ", ";
        v.erase(v.begin() + idx);

        if (idx == v.size()) {
            idx = 0;
        }
    }
    cout << v[0] << ">" << "\n";
    return 0;
}
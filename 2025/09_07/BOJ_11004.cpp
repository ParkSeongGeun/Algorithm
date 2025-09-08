#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    nth_element(v.begin(), v.begin() + k - 1, v.end());

    cout << v[k-1] << "\n";
    return 0;
}
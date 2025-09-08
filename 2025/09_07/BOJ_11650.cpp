#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int main() {
    cin >> n;

    vector<pair<int, int>> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());

    for(int i=0;i<n;i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}
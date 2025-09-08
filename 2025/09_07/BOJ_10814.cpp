#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
#include <queue>

using namespace std;

int n;

bool compare(pair<int, pair<string, int>>&p1, pair<int, pair<string, int>>&p2) {
    if (p1.first != p2.first) {
        return p1.first < p2.first;
    }
    return p1.second.second < p2.second.second;
}
int main() {
    cin >> n;

    vector<pair<int, pair<string, int>>> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second.first;
        v[i].second.second = i;
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0;i<n;i++){
        cout << v[i].first << " "  << v[i].second.first << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& p1, pair<int, int>& p2) {
    if(p1.second != p2.second) {
        return p1.second < p2.second;  // second 내림차순
    }
    return p1.first < p2.first;        // first 오름차순
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0; i<n; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}
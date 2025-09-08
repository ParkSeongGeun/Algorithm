#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool compare(pair<string, pair<int, pair<int, int>>>& p1, pair<string, pair<int, pair<int, int>>>& p2) {
    if (p1.second.first != p2.second.first) {
        return p1.second.first > p2.second.first;
    }

    if (p1.second.second.first != p2.second.second.first) {
        return p1.second.second.first < p2.second.second.first;
    }

    if (p1.second.second.second != p2.second.second.second) {
        return p1.second.second.second > p2.second.second.second;
    }  

    return p1.first < p2.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<string, pair<int, pair<int, int>>>> v(n);

    for(int i=0;i<n;i++){
        // 이름 -> 국어 -> 영어 -> 수학
        cin >> v[i].first >> v[i].second.first >> v[i].second.second.first >> v[i].second.second.second;
    }

    sort(v.begin(), v.end(), compare);

    for(int i=0;i<n;i++){
        cout << v[i].first << "\n";
    }

    return 0;
}
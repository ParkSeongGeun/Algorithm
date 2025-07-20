#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

int N, M;
int ans = INT_MAX;
int a[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int calculateDistance(const vector<pair<int, int>>& selectedChicken) {
    int totalDistance = 0;
    
    for(pair<int, int> h : house) {
        int minDist = INT_MAX;
        for(pair<int, int> c : selectedChicken) {
            int dist = abs(h.first - c.first) + abs(h.second - c.second);
            minDist = min(minDist, dist);
        }
        totalDistance += minDist;
    }
    
    return totalDistance;
}

void go(int idx, vector<pair<int, int>>& selected) {
    if (selected.size() == M) {
        int dist = calculateDistance(selected);
        ans = min(ans, dist);
        return;
    }

    if (idx >= chicken.size() || selected.size() + (chicken.size() - idx) < M) {
        return;
    }

    selected.push_back(chicken[idx]);
    go(idx+1, selected);
    selected.pop_back();

    go(idx+1, selected);
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) {
            cin >> a[i][j];

            if (a[i][j] == 1) {
                house.push_back(make_pair(i, j));
            }

            if (a[i][j] == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }

    vector<pair<int, int>> selected;
    go(0, selected);
    
    cout << ans << "\n";
    return 0;
}
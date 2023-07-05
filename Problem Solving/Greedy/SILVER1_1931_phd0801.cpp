#include <bits/stdc++.h>	

using namespace std;

int N;
vector<pair<int, int>> v;
int x, y;
int ans;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second)return a.first < b.first;
	return a.second < b.second;
};

int find_result() {
	ans = 1;
	pair<int, int> cur = v[0];
	for (auto iter = v.begin() + 1; iter != v.end(); iter++) {
		pair<int, int> next = (*iter);
		if (next.first >= cur.second) {
			ans++;
			cur = next;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
	cout << "---------------------------" << "\n";
	
	cout << find_result();
	return 0;
}
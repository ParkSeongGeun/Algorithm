#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
int value, ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		// 첫번째 원소 vs 두번째 원소*2
		value = v[i] * (i + 1);
		ans = max(ans, value);
	}
	cout << ans;
	return 0;
}
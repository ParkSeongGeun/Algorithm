#include <bits/stdc++.h>

using namespace std;

long long N, K;
long long ch[1000001];
long long sum;
long long l, r, mid;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> ch[i];
	}
	l = 1;
	r = 2e9;
	while (l+1 < r) {
		sum = 0;
		mid = (l + r) / 2;
		//cout << "l, mid, r" <<"-> "<< l << " - " << mid << " - " << r<<"\n";
		for (int i = 0; i < N;i++) {
			if (ch[i] < mid) {
				sum += (mid - ch[i]);
			}
		}
		//cout << sum << "\n";
		if (sum > K) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << l << "\n";
}
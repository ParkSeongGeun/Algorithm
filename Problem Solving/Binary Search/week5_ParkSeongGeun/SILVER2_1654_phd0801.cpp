#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[10001];
long long mid, l, r;

int main() {
	cin >> K >> N;
	int max = 0;
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	int ans=0;
	l = 1;
	r = max;

	while (l <= r) {
		int sum = 0;
		mid = (l + r) / 2;
		for (int i = 0; i < K; i++) {
			sum += (arr[i] / mid);
		}
		if (sum < N) {
			r = mid - 1;
		}
		else { // sum >= N
			l = mid + 1;
			if (ans < mid) {
				ans = mid;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long N, M; // <=1000000
long long arr[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	long long sum = 0;
	long long l = 0;
	long long r = 1LL * 1000000*M;
	long long mid;
	while (l+1<r) {
		sum = 0;
		mid = (l + r) / 2;
		for (int i = 0; i < N; i++) {
			sum +=  mid / arr[i];
		}
		if (sum >= M) {
			r = mid;
		}
		else { // sum<M;
			l = mid;
		}
	}
	cout<< r << '\n';
}
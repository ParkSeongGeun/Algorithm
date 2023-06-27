#include <bits/stdc++.h>

using namespace std;

long long N, M;
long long arr[300001];
long long l, r, mid;
long long sum;

bool check(int mid) {
	sum = 0;
	for (int i = 0; i < M; i++) {
		sum += arr[i] / mid;
		if (arr[i] % mid != 0) {
			sum++;
		}
	}
	if (sum > N) {
		return true;
	}
	return false;

}
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + M);
	long long min = arr[0];
	l = 0;
	r = arr[M-1]+1;
	long long ans = r;
	while (l + 1 < r) {
		sum = 0;
		mid = (l + r) / 2;
		//cout << "l , mid , r , sum -> " << l << " ,	" << mid << " , " << r << " , "<<sum<<"\n";
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid;
			if (ans > mid) {
				ans = mid;
			}
		}
		if (sum > N) {
			l = mid;
		}
	}
	//cout << "--------------" << "\n";
	cout << ans << "\n";
	return 0;
}
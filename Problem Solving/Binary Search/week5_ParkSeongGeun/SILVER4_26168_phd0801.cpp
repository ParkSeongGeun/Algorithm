#include <bits/stdc++.h>

using namespace std;

long long A[100001];
int B[100001];
int n;
int m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	sort(A, A + n);
	for (int i = 0; i < m; i++) {
		int c;
		cin >> c;
		if (c == 1) {
			long long k;
			cin >> k;
			cout << n- (lower_bound(A, A + n, k)-A)<<"\n";
		}
		else if (c == 2) {
			long long k;
			cin >> k;
			cout << n - (upper_bound(A, A + n, k) - A) << "\n";
		}
		else {
			long long x, y;
			cin >> x >> y;
			cout << upper_bound(A, A + n, y) - lower_bound(A, A + n, x) << "\n";
		}
	}
	return 0;
}
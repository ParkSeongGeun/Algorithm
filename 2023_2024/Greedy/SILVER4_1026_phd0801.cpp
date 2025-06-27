#include <bits/stdc++.h>	

using namespace std;

int N;
int A[51];
int B[51];
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	sort(A, A + N);
	sort(B, B + N);
	reverse(B, B+N);
	for (int i = 0; i < N; i++) {
		ans += A[i] * B[i];
	}
	cout << ans << '\n';
	return 0;
}
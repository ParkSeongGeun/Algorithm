#include <bits/stdc++.h>
	
using namespace std;

int N, ans;
int arr[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	reverse(arr, arr + N);
	for (int i = 0; i < N; i++) {
		ans += (i + 1) * arr[i];
	}
	cout << ans;
	return 0;
}
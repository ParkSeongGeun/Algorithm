#include <bits/stdc++.h>	

using namespace std;

int N;
long long arr[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += abs(arr[i] - arr[j]);
		}
	}
	cout << sum << "\n";
	return 0;
}

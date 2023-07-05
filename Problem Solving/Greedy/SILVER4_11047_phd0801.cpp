#include <bits/stdc++.h>

using namespace std;

int N, K;
int arr[11];
int a, b, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	int count = N;
	b = K;
	while (1) {
		if (count == 0) {
			break;
		}
		a = b / arr[count];
		if (a == 0) {
			count--;
			continue;
		}
		b = b - (a * arr[count]);
		c += a;
		count--;
		if (b == 0) {
			cout << c;
			break;
		}
	}
	return 0;
}
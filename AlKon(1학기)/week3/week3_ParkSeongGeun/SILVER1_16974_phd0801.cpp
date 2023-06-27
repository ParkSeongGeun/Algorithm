#include <bits/stdc++.h>

using namespace std;

long long burger[51];
long long patty[51];

long long getPatty(int n, long long x) {
	if (n == 0) {
		if (x == 1) {
			return 1;
		}
		else if (x == 0) {
			return 0;
		}
	}
	if (x == 1) {
		return 0;
	}
	else if (x <= burger[n - 1] + 1) {
		return getPatty(n - 1, x - 1);
	}
	else if (x == 1 + burger[n - 1] + 1) {
		return patty[n - 1] + 1;
	}
	else if (x <= 1 + burger[n - 1] + 1 + burger[n - 1]) {
		return patty[n - 1] + 1 + getPatty(n - 1, x - 1 - burger[n - 1] - 1);
	}
	else {
		return patty[n - 1] * 2 + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	burger[0] = 1;
	patty[0] = 1;
	int N;
	long long X;
	cin >> N >> X;
	for (int i = 1; i < N; i++) {
		burger[i] = 1 + burger[i - 1] + 1 + burger[i - 1] + 1;
		patty[i] = patty[i - 1] +1+ patty[i - 1];
	}
	cout << getPatty(N, X) << "\n";
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

long long mose(long long x) {
	if (x == 1) {
		return 0;
	}
	long long k;
	for (k = 1; k+k < x; k += k);
	return 1-(mose(x - k));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a;
	cin >> a;
	cout<<mose(a);
}
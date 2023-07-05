#include <bits/stdc++.h>

using namespace std;

unsigned long long n;
unsigned long long q;
int main() {

	cin >> n;

	q = sqrt(n);

	if ((q * q) < n) {
		++q;
	}

	cout << q;

	return 0;
}
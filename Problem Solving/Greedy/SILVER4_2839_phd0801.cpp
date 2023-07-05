#include <bits/stdc++.h>

using namespace std;

int N;
int check;
int result;
int a, b, c;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	a = N / 5;
	while (1) {
		b = N;
		c = b - a * 5;
		if (c%3 == 0) {
			break;
		}
		else {
			a--;
		}
		if (a < 0) {
			cout << "-1" << "\n";
			return 0;
		}
	}
	/*cout << a << "\n";
	cout << c / 3 << "\n";*/
	cout << c / 3 + a;
	return 0;
}
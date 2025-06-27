#include <bits/stdc++.h>

using namespace std;
int N;

void hanoi_tower(int front, int middle, int result, int k) {
	if (k == 0) {
		return;
	}
	hanoi_tower(front, result, middle, k - 1);
	// k를 front => result 로 이동
	cout << front << " " << result<<"\n";
	hanoi_tower(middle, front, result, k - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	string a = to_string(pow(2, N));
	int x = a.find('.');
	a = a.substr(0, x);
	a[a.length() - 1] -= 1;
	cout << a << "\n";
	if (N <= 20) {
		hanoi_tower(1, 2, 3, N);
	}
	return 0;
}
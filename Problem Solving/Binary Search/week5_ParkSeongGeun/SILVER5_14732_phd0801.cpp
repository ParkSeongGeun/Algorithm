#include <bits/stdc++.h>

using namespace std;

int MAP[501][501];
int sum;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++) {
			for (int k = y1; k < y2; k++) {
				if (MAP[j][k] == 0) {
					sum++;
					MAP[j][k] = 1;
				}
			}
		}
	}
	cout << sum << "\n";
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS	
#include <bits/stdc++.h>

using namespace std;

int BOX[50][50];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			BOX[i][j] = -1;
		}
	}
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			BOX[i][j] = s[j]-'0';
		}
	}
	int k = min(N, M)-1;
	int result=0;
	while (k >= 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if ((i + k) >= 50 || (j + k) >= 50) {
					break;
				}
				if (BOX[i][j] == BOX[i + k][j] &&
					BOX[i][j] == BOX[i][j + k] &&
					BOX[i][j] == BOX[i + k][j + k]) {
					result = max(result, (k + 1) * (k + 1));
					break;
				}
			}
		}
		k--;
	}
	cout << result;
	return 0;
}
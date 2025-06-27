#include <bits/stdc++.h>

using namespace std;

int N, M;
int MAP[10][10];

int dx[4] = {-1,0,1 };

int Solve(int y, int x, int last) { // DFS
	if (y == N) {
		return 0;
	}
	int cnt = INT_MAX;
	for (int i = 0; i < 3; i++) {
		if (i == last) {
			continue;
		}
		if (x + dx[i] < 0 || x + dx[i] >= M) {
			continue; //범위 밖으로 벗어날 수 없음
		}
		cnt = min(cnt, (Solve(y + 1, x + dx[i], i) + MAP[y][x]));
	}
	return cnt;
}

int go() {
	int min_value = INT_MAX;
	for (int i = 0; i < M; i++) { // 시작 위치 달리하기
		min_value = min(min_value, Solve(0, i, -1));
	}
	return min_value;
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}
	cout << go() << "\n";
	return 0;
}
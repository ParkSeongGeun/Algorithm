#include <bits/stdc++.h>
#define MAX_N 100

using namespace std;

int w, h, ans, cnt;

struct Node {
	bool is_visited;
	int data;
}MAP[MAX_N][MAX_N];

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1};

bool valid(int y, int x) {
	if (x < 0 or x >= MAX_N) {
		return false;
	}
	if (y < 0 or y >= MAX_N) {
		return false;
	}
	return true;
}

void dfs(int y_node, int x_node) {
	if (MAP[y_node][x_node].is_visited || MAP[y_node][x_node].data == 0) {
		return;
	}
	cnt++;
	MAP[y_node][x_node].is_visited = true;
	for (int i = 0; i < 8; i++) {
		if (valid(y_node+dy[i], x_node+dx[i])) {
			dfs(y_node + dy[i], x_node + dx[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b;
	while (1) {
		cin >> a >> b; // a´Â col , b´Â row
		if (a == 0 && b == 0) {
			return 0;
		}
		for (int i = 0; i < MAX_N; i++) {
			for (int j = 0; j < MAX_N; j++) {
				MAP[i][j].data = 0;
				MAP[i][j].is_visited = false;
			}
		}
		for (int i = 1; i <= b; i++) {
			for (int j = 1; j <= a; j++) {
				cin >> MAP[i][j].data;
			}
		}
		ans = 0;
		for (int i = 1; i <= b; i++) {
			for (int j = 1; j <= a; j++) {
				if (MAP[i][j].is_visited == true||MAP[i][j].data==0) {
					continue;
				}
				dfs(i, j);
				ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
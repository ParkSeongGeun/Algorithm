#include <bits/stdc++.h>
#define MAX_NODE 10010

using namespace std;

int N, ans=-1;
int x, y;
int MAP[MAX_NODE];
bool is_visited[MAX_NODE];

void bfs(int a) {
	queue<pair<int, int>>q;
	q.push({ a,0 });
	is_visited[a] = true;
	while (!q.empty()) {
		int cur_node = q.front().first;
		int time = q.front().second;
		int next = MAP[cur_node];
		q.pop();
		if (cur_node == y) {
			ans = time;
			return;
		}
		for (int i = 1; cur_node + (next * i) <= N; i++) {
			int next_node = cur_node + (next * i);
			if (!is_visited[next_node]) {
				is_visited[next_node] = true;
				q.push({ next_node, time + 1 });
			}
		}
		for (int i = 1; cur_node - (next * i) >= 1; i++) {
			int next_node = cur_node - (next * i);
			if (!is_visited[next_node]) {
				is_visited[next_node] = true;
				q.push({ next_node, time + 1 });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> MAP[i];
	}
	cin >> x >> y;
	bfs(x);
	cout << ans << "\n";
	return 0;
}
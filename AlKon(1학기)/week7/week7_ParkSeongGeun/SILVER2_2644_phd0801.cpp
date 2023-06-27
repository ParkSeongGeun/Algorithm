#include <bits/stdc++.h>	
#define MAX_NODE 100

using namespace std;

int n;
int x, y;
int k;
int ans;
vector<int> v[MAX_NODE];
bool is_visited[MAX_NODE];
void bfs(int cur_node) {
	queue<pair<int, int>> q;
	int check = 0;
	q.push({ cur_node, 0 });
	while (!q.empty()) {
		int next = q.front().first;
		int time = q.front().second;
		is_visited[next] = true;
		q.pop();
		for (int next_node : v[next]) {
			if (!is_visited[next_node]) {
				q.push({ next_node, time + 1 });
				if (next_node == y) {
					check = time + 1;
				}
			}
		}
	}
	if (check == 0) {
		ans = -1;
	}
	else {
		ans = check;
	}
}
int main() {
	cin >> n;
	cin >> x >> y;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(x);
	cout << ans << "\n";
	return 0;
}
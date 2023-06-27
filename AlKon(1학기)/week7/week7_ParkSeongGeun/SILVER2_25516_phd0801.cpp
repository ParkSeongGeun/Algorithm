#include <bits/stdc++.h>
#define MAX_NODE 100001

using namespace std;

int n, k;

int apple[MAX_NODE];

vector<int> v[MAX_NODE];
bool is_visited[MAX_NODE];

int ans;

void bfs(int cur_node) {
	queue<pair<int,int>> q;
	q.push({ cur_node, ans });
	is_visited[cur_node] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		if (apple[cur] == 1 && time <= k) {
			ans++;
			apple[cur] = 0;
		}
		q.pop();
		for (int next_node : v[cur]) {
			if (!is_visited[next_node]) {
				q.push({ next_node, time+1});
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		apple[i] = a;
	}
	bfs(0);
	cout << ans << "\n";
	return 0;
}
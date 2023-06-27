#include <bits/stdc++.h>
#define MAX_NODE 1001

using namespace std;

int N, M;
vector<int> v[MAX_NODE];
bool visited[MAX_NODE];
int ans = 0;

void dfs(int cur_node) {
	if (visited[cur_node] == true) {
		return;
	}
	visited[cur_node] = true;
	for (int next_node : v[cur_node]) {
		dfs(next_node);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == true) {
			continue;
		}
		dfs(i);
		ans++;
	}
	cout << ans << "\n";
	return 0;
}
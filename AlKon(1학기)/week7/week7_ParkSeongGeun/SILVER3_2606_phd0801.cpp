#include <bits/stdc++.h>	
#define MAX_NODE 101

using namespace std;

vector<int> v[MAX_NODE];
bool visited[MAX_NODE];

int N, M, ans;

void dfs(int cur_node) {
	if (visited[cur_node]) {
		return;
	}
	ans++;
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
	dfs(1);
	cout << ans-1 << "\n";
	return 0;
}

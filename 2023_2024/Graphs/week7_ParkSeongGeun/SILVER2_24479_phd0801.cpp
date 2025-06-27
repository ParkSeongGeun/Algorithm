#include <bits/stdc++.h>
#define MAX_NODE 100001
using namespace std;

int N, M, R;
vector<int> v[MAX_NODE];
bool visited[MAX_NODE];
int cnt[MAX_NODE];
int num;

void dfs(int cur_node) {
	num++;
	visited[cur_node] = true;
	cnt[cur_node] = num;
	for (int next_node : v[cur_node]) {
		if (!visited[next_node]) {
			dfs(next_node);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(R);
	for (int i = 1; i <= N; i++) {
		cout << cnt[i] << "\n";
	}
	return 0;
}

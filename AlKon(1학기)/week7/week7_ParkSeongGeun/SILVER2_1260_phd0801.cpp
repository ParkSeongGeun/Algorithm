#include <bits/stdc++.h>
#define MAX_NODE 1001

using namespace std;	

vector<int> dfs_graph[MAX_NODE];
queue<int> q;

bool visited[MAX_NODE];
bool visited2[MAX_NODE];

int N, M;
int start;

void dfs(int cur_node) {
	visited[cur_node] = true;
	cout << cur_node << " ";
	for (int next_node : dfs_graph[cur_node]) {
		if (!visited[next_node]) {
			dfs(next_node);
		}
	}
}
void bfs(int start_node) {
	q.push(start_node);
	int cur_node;
	visited2[start_node] = true;
	while (!q.empty()) {
		cur_node = q.front();
		q.pop();
		cout << cur_node << " ";
		for (int next_node : dfs_graph[cur_node]) {
			if (!visited2[next_node]) {
				q.push(next_node);
				visited2[next_node] = true;
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >>start;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		dfs_graph[a].push_back(b);
		dfs_graph[b].push_back(a);
		sort(dfs_graph[a].begin(), dfs_graph[a].end());
		sort(dfs_graph[b].begin(), dfs_graph[b].end());
	}
	dfs(start);
	cout << "\n";
	bfs(start);
	return 0;
}

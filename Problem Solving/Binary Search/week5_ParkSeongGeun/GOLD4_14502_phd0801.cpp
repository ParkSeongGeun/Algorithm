#include <bits/stdc++.h>

using namespace std;

int N, M;
int MAP[8][8];
vector<pair<int, int>> v;
vector<pair<int,int>> virus;
int res = -1;
int visited[8][8];

int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };


queue<pair<int, int>> q;

void do_bfs(int y, int x) {
	while (!q.empty()) {
		for (int i = 0; i < 4; i++) {
			int ny = q.front().first + dy[i];
			int nx = q.front().second + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) {
				continue;
			}
			if (visited[ny][nx] == 2)continue;
			if (MAP[ny][nx] == 1)continue;
			visited[ny][nx] = 2;
			q.push({ ny,nx });
		}
		q.pop();
	}	
}

int go() {
	memset(visited, 0, sizeof(visited));
	for (auto k : virus) {
		q = queue<pair<int,int>>();
		visited[k.first][k.second] = 2;
		q.push({ k.first, k.second });
		do_bfs(k.first, k.second);
	}
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 0&&visited[i][j]==0) {
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) { // ¸Ê ¼±ÅÃ
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 0) {
				v.push_back({ i,j });
			}
			if (MAP[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}
	int res = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				MAP[v[i].first][v[i].second] = 1;
				MAP[v[j].first][v[j].second] = 1;
				MAP[v[k].first][v[k].second] = 1;
				res = max(res, go());
				MAP[v[i].first][v[i].second] = 0;
				MAP[v[j].first][v[j].second] = 0;
				MAP[v[k].first][v[k].second] = 0;
			}
		}
	}
	cout << res << "\n";
	return 0;
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << MAP[i][j];
		}
		cout << "\n";
	}*/
}
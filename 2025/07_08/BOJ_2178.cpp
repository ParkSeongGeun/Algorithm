#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M, ny, nx, y, x;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char MAP[101][101];
int visited[101][101];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> MAP[i][j];
    }
  }

  queue<pair<int, int>> q;
  visited[1][1] = 1;
  q.push({1, 1});

  while (q.size()) {
    tie(y, x) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      ny = y + dy[i];
      nx = x + dx[i];

      if ((ny <= 0 || ny > N || nx <= 0 || nx > M) || MAP[ny][nx] != '1') {
        continue;
      }

      if (visited[ny][nx]) {
        continue;
      }

      visited[ny][nx] = visited[y][x] + 1;
      q.push({ny, nx});
    }
  }

  //   for (int i = 1; i <= 4; i++) {
  //     for (int j = 1; j <= 6; j++) {
  //       cout << visited[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }
  cout << visited[N][M] << "\n";
  return 0;
}
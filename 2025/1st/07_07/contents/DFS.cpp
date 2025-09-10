#include <iostream>

using namespace std;

int MAP[101][101];
bool visited[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int ans;
int m, n, ny, nx;

void DFS(int y, int x) {
  visited[y][x] = 1;
  for (int i = 0; i < 4; i++) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
      continue;
    }
    if (MAP[ny][nx] == 1 && !visited[ny][nx]) {
      DFS(ny, nx);
    }
  }
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> MAP[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (MAP[i][j] == 1 && !visited[i][j]) {
        ans++;
        DFS(i, j);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
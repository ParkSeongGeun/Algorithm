#include <cstring>
#include <iostream>

using namespace std;

int N, x, y, nx, ny, ans, cnt, val;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int MAP[101][101];
int copy_MAP[101][101];
bool visited[101][101];

void dfs(int py, int px) {
  if (!copy_MAP[py][px]) {
    return;
  }

  if (visited[py][px]) {
    return;
  }

  visited[py][px] = true;

  for (int i = 0; i < 4; i++) {
    ny = py + dy[i];
    nx = px + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= N || (copy_MAP[ny][nx] <= 0)) {
      continue;
    }

    dfs(ny, nx);
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> MAP[i][j];
      if (MAP[i][j] > val) {
        val = MAP[i][j];
      }
    }
  }

  // 가장 큰 val까지 다 침수 시킨다.
  for (int k = 0; k <= val; k++) {
    cnt = 0;
    // 복사한 맵
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        copy_MAP[i][j] = MAP[i][j] - k;
      }
    }

    // for (int i = 0; i < N; i++) {
    //   for (int j = 0; j < N; j++) {
    //     cout << copy_MAP[i][j] << " ";
    //   }
    //   cout << "\n";
    // }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j] && (copy_MAP[i][j] > 0)) {
          cnt++;
          dfs(i, j);
        }
      }
    }

    // ans
    if (cnt > ans) {
      ans = cnt;
    }

    // visited 초기화
    memset(visited, false, sizeof(visited));
    memset(copy_MAP, 0, sizeof(copy_MAP));
  }

  cout << ans << "\n";
  return 0;
}
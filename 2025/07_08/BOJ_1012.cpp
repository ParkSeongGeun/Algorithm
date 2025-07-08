#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int T, M, N, K;
int y, x, ny, nx, ans;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int MAP[51][51];
bool visited[51][51];

void dfs(int py, int px) {
  if (visited[py][px]) {
    return;
  }

  if (!MAP[py][px]) {
    return;
  }

  // cout << "py, px: " << py << "," << px << "\n";
  visited[py][px] = true;

  for (int i = 0; i < 4; i++) {
    ny = py + dy[i];
    nx = px + dx[i];

    if (ny < 0 || ny >= N || nx < 0 || nx >= M || !MAP[ny][nx]) {
      continue;
    }

    dfs(ny, nx);
  }
}

int main() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> M >> N >> K;

    for (int j = 0; j < K; j++) {
      int y, x;
      cin >> y >> x;
      MAP[x][y] = 1;
    }

    // for (int j = 0; j < N; j++) {
    //   for (int k = 0; k < M; k++) {
    //     cout << MAP[j][k] << " ";
    //   }
    //   cout << "\n";
    // }

    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (!visited[j][k] && MAP[j][k]) {
          ans++;
          dfs(j, k);
        }
      }
    }

    cout << ans << "\n";

    // 안전빵으로 여기서 MAP, visited, ans 초기화
    ans = 0;
    memset(visited, false, sizeof(visited));
    memset(MAP, 0, sizeof(MAP));
  }

  return 0;
}
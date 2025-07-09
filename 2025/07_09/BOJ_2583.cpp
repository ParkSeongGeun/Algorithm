#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int m, n, k, x, xx, y, yy, nx, ny, area_count;
int a[104][104];
bool visited[104][104];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
vector<int> ret;

void dfs(int py, int px) {
  if (py < 0 || py >= m || px < 0 || px >= n) {
    return;
  }

  if (visited[py][px] || a[py][px] == 1) {
    return;
  }

  visited[py][px] = true;
  area_count++;

  for (int i = 0; i < 4; i++) {
    ny = py + dy[i];
    nx = px + dx[i];
    dfs(ny, nx);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> m >> n >> k;

  // 직사각형 그리기
  for (int i = 0; i < k; i++) {
    cin >> x >> y >> xx >> yy;
    for (int i = x; i < xx; i++) {
      for (int j = y; j < yy; j++) {
        a[j][i] = 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != 1 && !visited[i][j]) {
        area_count = 0;
        dfs(i, j);
        ret.push_back(area_count);
      }
    }
  }

  sort(ret.begin(), ret.end());
  cout << ret.size() << "\n";
  for (int area : ret) {
    cout << area << " ";
  }
  cout << "\n";

  return 0;
}
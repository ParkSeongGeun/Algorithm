#include <cstring>
#include <iostream>

using namespace std;

int N, M, J, res;
int screen[11];

int main() {
  cin >> N >> M;
  // 미리 만들어
  for (int i = 1; i <= M; i++) {
    screen[i] = 1;
  }

  cin >> J;
  for (int i = 0; i < J; i++) {
    int ap;
    cin >> ap;

    // 바로 최단 경로로 가.
    // - 일단 사과 떨어지는 게 바구니 좌/우/현위치 인지 판단
    int left = N, right = 1;
    for (int j = 1; j <= N; j++) {
      if (screen[j]) {
        if (j < left) {
          left = j;
        }

        if (j > right) {
          right = j;
        }
      }
    }

    // left, right는 바구니의 현재 left / right 상황을 보기 위함.
    // cout << "res: " << res << "->" << left << ", " << right << "\n";

    // 사과가 바구니 왼쪽에서 떨어질 때
    memset(screen, 0, sizeof(screen));

    if (ap < left) {
      res += (left - ap);

      for (int j = ap; j < ap + M; j++) {
        screen[j] = 1;
      }
    }
    // 사과가 바구니 오른쪽에서 떨어질 때
    else if (ap > right) {
      res += (ap - right);

      for (int j = ap - M + 1; j <= ap; j++) {
        screen[j] = 1;
      }
    }
    // 사과가 바구니 사이에서 떨어질 때
    else {
      res += 0;
      for (int j = left; j <= right; j++) {
        screen[j] = 1;
      }
    }
  }

  cout << res << "\n";
}
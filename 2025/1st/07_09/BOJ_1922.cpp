#include <iostream>
#include <string>

using namespace std;

int N;
char MAP[101][101];
int ret;

string quad(int y, int x, int size) {
  // 기저 사례
  if (size == 1) {
    return string(1, MAP[y][x]);
  }

  char b = MAP[y][x];
  string ret = "";

  for (int i = y; i < y + size; i++) {
    for (int j = x; j < x + size; j++) {
      if (b != MAP[i][j]) {
        ret += '(';
        ret += quad(y, x, size / 2);
        ret += quad(y, x + size / 2, size / 2);
        ret += quad(y + size / 2, x, size / 2);
        ret += quad(y + size / 2, x + size / 2, size / 2);
        ret += ')';
        return ret;
      }
    }
  }
  return string(1, MAP[y][x]);
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> MAP[i][j];
    }
  }
  cout << quad(0, 0, N) << "\n";
  return 0;
}
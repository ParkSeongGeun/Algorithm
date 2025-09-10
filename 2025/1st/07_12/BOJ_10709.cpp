#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int H, W;
// H X W 배열
vector<string> v;
int res[101][101];

int main() {
  cin >> H >> W;

  memset(res, -1, sizeof(res));
  for (int i = 0; i < H; i++) {
    string c;
    cin >> c;
    v.push_back(c);
  }

  for (int i = 0; i < H; i++) {
    string &str = v[i];
    int len = str.length();
    // 맨 처음 c가 나올 때 까지는 -1
    int currentPos = v[i].find('0');

    while (currentPos < len) {
      if (str[currentPos] == 'c') {
        res[i][currentPos] = 0; // 'c' 위치는 0으로

        // 다음 'c'를 찾음
        int nextC = str.find('c', currentPos + 1);

        // 다음 'c'가 없으면 끝까지 1, 2, 3... 으로 채움
        if (nextC == string::npos) {
          int counter = 1;
          for (int j = currentPos + 1; j < len; j++) {
            res[i][j] = counter++;
          }
          break;
        }
        // 다음 'c'가 있으면 그 사이를 1, 2, 3... 으로 채움
        else {
          int counter = 1;
          for (int j = currentPos + 1; j < nextC; j++) {
            res[i][j] = counter++;
          }
          currentPos = nextC;
        }
      } else {
        currentPos++;
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << res[i][j] << " ";
    }
    cout << "\n";
  }
}
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

ll T, N, ret, num;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;
    ret = 0;
    num = 5;

    while (num <= N) {
      ret = ret + (N / num);
      num *= 5;
    }
    cout << ret << "\n";
  }

  return 0;
}
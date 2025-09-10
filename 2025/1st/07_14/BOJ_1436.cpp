#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef unsigned long long ll;

int N;
ll ans;

int main() {
  cin >> N;

  int cnt = 666;
  int a = 0;
  while (true) {
    string s = to_string(cnt);

    if (s.find("666") != -1) {
      a++;
      if (a == N) {
        cout << s << "\n";
        break;
      }
    }
    cnt++;
  }

  return 0;
}
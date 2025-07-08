#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

ll a;

int main() {
  while (scanf("%lld", &a) != EOF) {
    ll cnt = 1, ret = 1;
    while (true) {
      if (cnt % a == 0) {
        cout << ret << "\n";
        break;
      } else {
        cnt = ((cnt * 10) + 1) % a;
        ret++;
      }
    }
  }

  return 0;
}
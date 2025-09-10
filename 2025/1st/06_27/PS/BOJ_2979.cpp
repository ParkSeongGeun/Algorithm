#include <iostream>
#include <map>

using namespace std;

// 1 2 3 4 5 6 7 8
// A A A A A
//     B B
//   C C C C C C

int a, b, c;
map<int, int> mp;

int main() {
  cin >> a >> b >> c;
  for (int i = 0; i < 3; i++) {
    int first, second;
    cin >> first >> second;
    for (int j = first; j < second; j++) {
      mp[j] += 1;
    }
  }

  int sum = 0;

  for (int i = 1; i <= 100; i++) {
    if (mp[i] == 1) {
      sum += a;
    } else if (mp[i] == 2) {
      sum += b * 2;
    } else if (mp[i] == 3) {
      sum += c * 3;
    }
  }

  cout << sum << "\n";
  return 0;
}

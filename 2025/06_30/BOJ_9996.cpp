#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  string s;

  cin >> n;
  cin >> s;

  auto it = s.find("*");
  string front = s.substr(0, it);
  string back = s.substr(it + 1);

  for (int i = 0; i < n; i++) {
    string c;
    cin >> c;

    if (front.size() + back.size() > c.size()) {
      cout << "NE"
           << "\n";
    } else {
      if (c.substr(0, front.size()) == front &&
          c.substr(c.size() - back.size()) == back) {
        cout << "DA"
             << "\n";
      } else {
        cout << "NE"
             << "\n";
      }
    }
  }

  return 0;
}
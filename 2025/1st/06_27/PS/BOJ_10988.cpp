#include <algorithm>
#include <iostream>

using namespace std;

vector<char> v;
int main() {
  string s;
  cin >> s;

  string r = s;

  for (char c : s) {
    v.push_back(c);
  }

  reverse(s.begin(), s.end());
  if (r == s) {
    cout << 1 << "\n";
  } else {
    cout << 0 << "\n";
  }

  return 0;
}
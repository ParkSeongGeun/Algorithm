#include <iostream>

using namespace std;

int main() {
  string s;

  getline(cin, s);

  for (int i = 0; i < s.length(); i++) {
    char c = s[i];
    if ('a' <= c && c <= 'z') {
      s[i] = 'a' + (c - 'a' + 13) % 26;
    } else if ('A' <= c && c <= 'Z') {
      s[i] = 'A' + (c - 'A' + 13) % 26;
    }
  }

  cout << s << "\n";
  return 0;
}
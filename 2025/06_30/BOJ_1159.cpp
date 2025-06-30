#include <iostream>
#include <map>

using namespace std;

int n;
string s;
map<char, int> mp;

int main() {
  cin >> n;

  for (char c = 'a'; c <= 'z'; c++) {
    mp[c]++;
  }

  for (int i = 0; i < n; i++) {
    cin >> s;
    mp[s[0]]++;
  }

  int total = 0;
  for (char c = 'a'; c <= 'z'; c++) {
    if (mp[c] >= 6) {
      cout << c;
      total++;
    }
  }

  if (!total) {
    cout << "PREDAJA"
         << "\n";
  }

  return 0;
}
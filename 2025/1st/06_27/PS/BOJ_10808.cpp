#include <iostream>
#include <map>

using namespace std;

string s;
map<char, int> mp;
int main() {
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    mp[s[i]] += 1;
  }

  for (char c = 'a'; c <= 'z'; c++) {
    cout << mp[c] << " ";
  }

  return 0;
}
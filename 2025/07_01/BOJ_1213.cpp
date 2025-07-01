#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

string s;
map<char, int> cnt;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;

  for (char c : s) {
    cnt[c]++;
  }

  int oddCount = 0;
  char oddChar = 0;

  for (auto &p : cnt) {
    if (p.second % 2 == 1) {
      oddCount++;
      oddChar = p.first;
    }
  }

  // 팰린드롬 불가능한 경우
  if (oddCount > 1) {
    cout << "I'm Sorry Hansoo\n";
    return 0;
  }

  string res = "";

  for (auto &p : cnt) {
    for (int i = 0; i < p.second / 2; i++) {
      res += p.first;
    }
  }

  string ans = res;

  if (oddCount == 1) {
    ans += oddChar;
  }

  reverse(res.begin(), res.end());
  ans += res;

  cout << ans << "\n";

  return 0;
}
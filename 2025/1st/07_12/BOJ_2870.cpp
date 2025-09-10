#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string s;
int N;
vector<string> v;

// 0잇으면 정리 -> 생략 가능
bool compare(const string &s1, const string &s2) {
  if (s1.length() != s2.length()) {
    return s1.length() < s2.length();
  }
  return s1 < s2;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    string cnt = "";
    // l03za4
    for (int j = 0; j < s.length(); j++) {
      if ('0' <= s[j] && s[j] <= '9') {
        cnt += s[j];
      } else {
        if (cnt.length()) {
          if (cnt[0] == '0') {
            auto it = cnt.find_first_not_of('0');
            cnt.erase(0, it);
            if (cnt.length() == 0) {
              cnt = '0';
            }
          }
          v.push_back(cnt);
        }
        cnt = "";
      }
    }

    if (cnt.length()) {
      if (cnt[0] == '0') {
        // '0' 일때
        if (cnt.length() != 1) {
          auto it = cnt.find_first_not_of('0');
          cnt.erase(0, it);
          if (cnt.length() == 0) {
            cnt = '0';
          }
        }
      }
      v.push_back(cnt);
    }
  }

  sort(v.begin(), v.end(), compare);

  for (string s : v) {
    cout << s << "\n";
  }

  return 0;
}
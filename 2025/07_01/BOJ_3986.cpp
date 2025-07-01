#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;
int n, res;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> s;
    stack<char> stk;
    stk.push(s[0]);
    for (int j = 1; j < s.length(); j++) {
      if (stk.size() == 0) {
        stk.push(s[j]);
      } else if (s[j] == stk.top()) {
        stk.pop();
      } else {
        stk.push(s[j]);
      }
    }

    if (stk.size() == 0) {
      res++;
    }
  }

  cout << res << "\n";
  return 0;
}
#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string s;

int main() {
  while (true) {
    getline(cin, s);

    if (s == ".") {
      break;
    }

    stack<int> stk;
    bool check = true;

    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ')') {
        if (stk.size() == 0 || stk.top() == '[') {
          check = false;
          break;
        } else {
          stk.pop();
        }
      }

      if (s[i] == ']') {
        if (stk.size() == 0 || stk.top() == '(') {
          check = false;
          break;
        } else {
          stk.pop();
        }
      }

      if (s[i] == '(') {
        stk.push(s[i]);
      }

      if (s[i] == '[') {
        stk.push(s[i]);
      }
    }
    if (check && stk.size() == 0) {
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
  }
  return 0;
}
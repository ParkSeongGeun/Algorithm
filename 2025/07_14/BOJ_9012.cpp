#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <vector>

using namespace std;

int N;

int main() {
  cin >> N;

  string s;
  for (int i = 0; i < N; i++) {
    stack<char> stk;

    cin >> s;

    for (int j = 0; j < s.length(); j++) {
      if (stk.size()) {
        char fr = stk.top();

        if (fr == '(' && s[j] == ')') {
          stk.pop();
          continue;
        } else {
          stk.push(s[j]);
        }
      } else {
        stk.push(s[j]);
      }
    }

    if (stk.size()) {
      cout << "NO"
           << "\n";
    } else {
      cout << "YES"
           << "\n";
    }
  }
}
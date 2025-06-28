#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
int main() {
  for (int i = 0; i < 9; i++) {
    int cur;
    cin >> cur;
    a.push_back(cur);
  }

  sort(a.begin(), a.end());

  do {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
      sum += a[i];
    }
    if (sum == 100) {
      for (int i = 0; i < 7; i++) {
        cout << a[i] << "\n";
      }
      return 0;
    }

  } while (next_permutation(a.begin(), a.end()));

  return 0;
}
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

int N, n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> n;
    map<string, int> mp;
    for (int j = 0; j < n; j++) {
      string key;
      string value;
      cin >> value >> key;
      mp[key]++;
    }

    for (pair<string, int> p : mp) {
      // cout << p.first << ", " << p.second << "\n";
    }

    int ans = 1;
    for (pair<string, int> p : mp) {
      ans *= (p.second + 1);
    }

    cout << ans - 1 << "\n";
  }
}

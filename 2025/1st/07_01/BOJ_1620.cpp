#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int N, M;
map<string, int> mp1;
map<int, string> mp2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;

  string s;

  for (int i = 0; i < N; i++) {
    cin >> s;
    mp2[i + 1] = s;
    mp1[s] = i + 1;
  }

  for (int i = 0; i < M; i++) {
    string cnt;
    cin >> cnt;

    if (('a' <= cnt[0] && cnt[0] <= 'z') || ('A' <= cnt[0] && cnt[0] <= 'Z')) {
      cout << mp1[cnt] << "\n";
    } else {
      cout << mp2[stoi(cnt)] << "\n";
    }
  }
  return 0;
}
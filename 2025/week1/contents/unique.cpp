#include <algorithm>
#include <iostream>

using namespace std;

vector<int> v{2, 2, 1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9};

int main() {
  sort(v.begin(), v.end());
  auto it = v.erase(unique(v.begin(), v.end()), v.end());
  for (int i : v)
    cout << i << " ";
  cout << "\n";
  return 0;
}
// map<int, int> mp;
// int main() {
//   vector<int> v = {1, 2, 3, 1, 2, 3};
//   for (int i : v) {
//     if (mp[i]) {
//       continue;
//     } else {
//       mp[i] = 1;
//     }
//   }
//   vector<int> ret;
//   for (auto it : mp) {
//     ret.push_back(it.first);
//   }
//   for (int i : ret) {
//     cout << i << "\n";
//   }
//   return 0;
// }
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<vector<int>> res;

void print() { res.push_back(v); }

void make_permutation(int n, int r, int depth) {
  if (r == depth) {
    print();
    return;
  }

  for (int i = depth; i < n; i++) {
    swap(v[i], v[depth]);
    make_permutation(n, r, depth + 1);
    swap(v[i], v[depth]);
  }
  return;
}

int main() {
  int n;
  cin >> n;
  int r = n;

  for (int i = 1; i <= n; i++) {
    v.push_back(i);
  }

  make_permutation(n, r, 0);

  // 주의할 점 -> swap을 이용해 구현한 순열은 오름차순을 보장하지 않음.
  sort(res.begin(), res.end());
  for (auto it : res) {
    for (int i : it) {
      cout << i << " ";
    }
    cout << "\n";
  }
  return 0;
}

// int main() {
//   int n;
//   cin >> n;

//   vector<int> v;
//   for (int i = 1; i <= n; i++) {
//     v.push_back(i);
//   }

//   do {
//     for (int i : v) {
//       cout << i << " ";
//     }
//     cout << "\n";
//   } while (next_permutation(v.begin(), v.end()));
//   return 0;
// }
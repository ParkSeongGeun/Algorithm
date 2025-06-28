#include <algorithm>
#include <iostream>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};
int n = 5, r = 3;

void print() {
  for (int i = 0; i < r; i++) {
    cout << a[i] << " ";
  }
  cout << "\n";
}

void makePermuation(int n, int r, int depth) {
  if (r == depth) {
    print();
    return;
  }

  for (int i = depth; i < n; i++) {
    cout << i << " : " << depth << "를 바꾼다!\n";
    swap(a[i], a[depth]);
    makePermuation(n, r, depth + 1);
    swap(a[i], a[depth]);
  }
  return;
}
int main() {
  // using next_permutation
  //   vector<int> a;
  //   a.push_back(1);
  //   a.push_back(2);
  //   a.push_back(3);

  //   do {
  //     for (int i : a) {
  //       cout << i << " ";
  //     }
  //     cout << "\n";
  //   } while (next_permutation(a.begin(), a.end()));
  makePermuation(n, r, 0);
  return 0;
}
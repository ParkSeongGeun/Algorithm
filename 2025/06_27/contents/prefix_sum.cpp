#include <iostream>

using namespace std;

int a[100001];
int prefix_sum[100001];
int n, m;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    prefix_sum[i] = prefix_sum[i - 1] + a[i];
  }

  int b, c;
  for (int i = 0; i < m; i++) {
    cin >> b >> c;
    cout << prefix_sum[c] - prefix_sum[b - 1] << "\n";
  }
  return 0;
}
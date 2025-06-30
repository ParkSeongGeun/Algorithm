#include <algorithm>
#include <iostream>

using namespace std;

// int N, K;
// int cnt;
// int arr[100001];
// int res[100001];

// int main() {
//   cin >> N >> K;
//   for (int i = 1; i <= N; i++) {
//     cin >> cnt;
//     arr[i] = cnt;

//     if (i == K) {
//       for (int j = 1; j <= K; j++) {
//         res[i] += arr[j];
//       }
//     }

//     if (i > K) {
//       res[i] = res[i - 1] + arr[i] - arr[i - K];
//     }
//   }

//   int result = -100000001;
//   for (int i = K; i <= N; i++) {
//     if (res[i] >= result) {
//       result = res[i];
//     }
//   }

//   cout << result << "\n";
//   return 0;
// }

int n, k, temp, psum[100001], ret = -10000000;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    psum[i] = psum[i - 1] + temp;
  }

  for (int i = k; i <= n; i++) {
    ret = max(ret, psum[i] - psum[i - k]);
  }

  cout << ret << "\n";
  return 0;
}
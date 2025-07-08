#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

ll a, b, c, k;

ll go(int b) {
  cout << "go(" << b << ") 호출\n";

  // 기저 조건 1: a^0 = 1
  if (b == 0) {
    cout << "b=0이므로 1 반환\n";
    return 1;
  }

  // 기저 조건 2: a^1 = a
  if (b == 1) {
    cout << "b=1이므로 " << a << " % " << c << " = " << (a % c) << " 반환\n";
    return a % c;
  }

  // 재귀: a^b = (a^(b/2))^2 또는 (a^(b/2))^2 * a
  cout << "go(" << b / 2 << ") 계산 중...\n";
  k = go(b / 2) % c; // a^(b/2) 계산
  cout << "go(" << b / 2 << ") = " << k << "\n";

  if (b % 2 == 0) {
    // b가 짝수: a^b = (a^(b/2))^2
    cout << b << "는 짝수이므로: " << k << " * " << k << " % " << c << "\n";
    return k * k % c;
  } else {
    // b가 홀수: a^b = (a^(b/2))^2 * a
    cout << b << "는 홀수이므로: " << k << " * " << k << " * " << a << " % "
         << c << "\n";
    return k * k % c * a % c;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c;
  cout << "\n=== " << a << "^" << b << " % " << c << " 계산 과정 ===\n\n";

  ll result = go(b);

  cout << "\n=== 최종 결과 ===\n";
  cout << result << "\n";

  return 0;
}
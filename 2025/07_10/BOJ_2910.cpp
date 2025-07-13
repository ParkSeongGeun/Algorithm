#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;

ll N, C;

// {value, 빈도, 첫 등장 인덱스}
vector<pair<pair<ll, ll>, ll>> v;

bool compare(const pair<pair<ll, ll>, ll> &a, const pair<pair<ll, ll>, ll> &b) {
  // 빈도가 다르면 빈도순 내림차순
  if (a.first.second != b.first.second) {
    return a.first.second > b.first.second;
  }
  // 빈도가 같으면 첫 등장 순서순 오름차순
  return a.second < b.second;
}

int main() {
  cin >> N >> C;

  ll num;
  for (int i = 0; i < N; i++) {
    cin >> num;
    bool isIn = false;
    for (int j = 0; j < v.size(); j++) {
      if (v[j].first.first == num) {
        v[j].first.second++; // 빈도 증가
        isIn = true;
        break;
      }
    }

    if (!isIn) {
      // {value, 빈도}, 첫 등장 인덱스
      v.push_back(make_pair(make_pair(num, 1), i));
    }
  }

  sort(v.begin(), v.end(), compare);

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].first.second; j++) {
      cout << v[i].first.first << " ";
    }
  }

  return 0;
}
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int N, prevT;
int one, oneTime;
int two, twoTime;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int team, minute, second;
    string time;
    cin >> team >> time;

    // parsing
    string m, s;
    m = time.substr(0, 2);
    s = time.substr(3);
    minute = stoi(m);
    second = stoi(s);

    // score 비교 후 시간 추가해주기
    if (one > two) {
      oneTime += (minute * 60 + second - prevT);
    } else if (one < two) {
      twoTime += (minute * 60 + second - prevT);
    }

    // 팀에 따른 점수 추가
    if (team == 1) {
      one++;
    } else {
      two++;
    }

    // 이전시간을 가지고 더해주기
    prevT = (minute * 60) + second;
  }

  if (one > two) {
    oneTime += (48 * 60 - prevT);
  } else if (one < two) {
    twoTime += (48 * 60 - prevT);
  }

  printf("%02d:%02d\n", oneTime / 60, oneTime % 60);
  printf("%02d:%02d\n", twoTime / 60, twoTime % 60);
}
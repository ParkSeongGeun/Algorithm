#include <bits/stdc++.h>	

using namespace std;

int n, r, c;
int ans;

// 재귀적으로 문제를 푼다
// 그 전 상황이 어떻게 풀이되는 지 증명할 수 있긴 하지만..
// -by 김성렬 교수님 -> 믿어라! 전의 과정이 된다고!
void Z(int y, int x, int size) // 분할 정복 알고리즘 함수(시작 y, 시작 x, 변의 길이) 이런식으로..연습
{
	if (y == r && x == c) {
		cout << ans << '\n';
		return;
	} 
	// 조사하는 사분면 내에 존재한다면
	if (r < y + size && r >= y && c < x + size && c >= x) {
		// 사분면 내에 존재한다면
	   // 구역을 4등분으로 쪼갠 뒤에 쪼갠 부분을 각각 사분면으로 나누어 생각해보자
		// 1사분면 탐색 --> 된다고..믿자!
		Z(y, x, size / 2);
		// 2사분면 탐색
		Z(y, x + size / 2, size / 2);
		// 3사분면 탐색
		Z(y + size / 2, x, size / 2);
		// 4사분면 탐색
		Z(y + size / 2, x + size / 2, size / 2);
	}
	else { // 사분면 내에 없다면 거기 박스 크기만큼 ans에 더하기
		ans += size * size;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r >> c;
	Z(0, 0, pow(2, n));
	return 0;
}
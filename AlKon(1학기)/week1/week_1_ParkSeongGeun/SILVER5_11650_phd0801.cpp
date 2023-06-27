#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> v; // (x,y)좌표 입력받을 때 pair 객체 사용

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y; // x,y입력 시
		v.push_back(make_pair(x, y)); // pair객체로 v에 push_back하기
	}
	sort(v.begin(), v.end()); // sort(v.begin(), v.end()) 시 pair객체에서 x좌표가 같으면 알아서 y좌표로 정렬됨
	for (auto i = v.begin(); i != v.end(); i++) { // v.begin() 사용해 반복자로 접근해서 v.end()까지 반복문 돌리기
		cout << i->first << " " << i->second << "\n"; // *i.first == (i->first), *i.second == (i->second)
	}
	return 0;
}
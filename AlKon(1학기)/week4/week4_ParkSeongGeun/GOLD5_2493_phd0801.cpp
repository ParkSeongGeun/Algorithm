#include <bits/stdc++.h>	

using namespace std;

//int seq[500001];
//int ans[500001];
//stack<int> s;
stack<pair<int, int>> s; // x -> 높이 , y -> 인덱스

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	s.push({ 100000001,0 });
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		while (s.top().first < a) {
			s.pop();
		}
		cout << s.top().second << " ";
		s.push({ a, i });
	}
	return 0;
	// 이 코드로 구현하니 stack에서 pop한 후에 인덱스 설정이 어려워졌다.
	// 이로 인해 pair<x,y>를 사용하자고 마음 먹었다.
	/*for (int i = 1; i <= N; i++) {
		cin >> seq[i];
	}
	for (int i = N; i >= 1; i--) {
		int count = 0;
		while (!s.empty() && s.top() <= seq[i]) {
			s.pop();
			count++;
		}
		for (int j= 1; j <= count; j++) {	
			ans[i + j] = max(ans[i+j],i);
		}
		s.push(seq[i]);
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}*/
}
#include <bits/stdc++.h>	

using namespace std;

//int seq[500001];
//int ans[500001];
//stack<int> s;
stack<pair<int, int>> s; // x -> ���� , y -> �ε���

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
	// �� �ڵ�� �����ϴ� stack���� pop�� �Ŀ� �ε��� ������ ���������.
	// �̷� ���� pair<x,y>�� ������ڰ� ���� �Ծ���.
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
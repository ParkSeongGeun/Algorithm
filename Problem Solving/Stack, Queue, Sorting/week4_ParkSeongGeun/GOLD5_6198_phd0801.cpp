#include <bits/stdc++.h>	

using namespace std;

int seq[80001];
int N;
stack<pair<int, int>> s;
int j;
int main() {
	cin >> N;
	long long count = 0; //  79999 + .... + 1 = �� 32��... int �������δ� �Ұ� -> long long �ڷ��� �����ϱ�..
	for (int i = 1; i <= N; i++) {
		cin >> seq[i];
	}
	s.push({ 1000000001,0 });
	for (int i = N, j=1; i >= 1; i--,j++) {
		while (!s.empty()&&seq[i] > s.top().first) {
			s.pop();
		}
		count += j - s.top().second - 1;
		s.push({ seq[i],j });
	}
	cout << count << "\n";
	return 0;
}
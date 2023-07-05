#include <bits/stdc++.h>

using namespace std;

int N;
int m;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> m;
	cout << "<";
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
		for (int i = 1; i < m; i++) {
			int b = q.front();
			q.pop();
			q.push(b);
		}
		cout << q.front() << ", ";
		q.pop();
	}
	cout << ">";
	return 0;
}
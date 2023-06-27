#include <bits/stdc++.h>

using namespace std;

stack<int> s;
int now[1000001];
int ans[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> now[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= now[i]) {
			s.pop();
		}
		if (s.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = s.top();
		}
		s.push(now[i]);
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}
/*
	/*stack<int> input_1;
	stack<int> first;
	stack<int> second;
	stack<int> final;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		input_1.push(a);
	}*/
	/*for (int i = 0; i < N; i++) {
		int b = input_1.top();
		if (c == b) {

		}
		c = b;
		if (first.size() == 0) {
			first.push(b);
			final.push(-1);
			input_1.pop();
			continue;
		}
		
		if (b > first.top()) {
			first.pop();
			final.push(-1);
			first.push(b);
			input_1.pop();
			continue;
		}
		if (b < first.top()) {
			final.push(first.top());
			if (second.size() == 0) {
				second.push(b);
				input_1.pop();
				continue;
			}
			else {
				if (b < second.top()) {
					final.pop();
					final.push(second.top());
					second.pop();
					second.push(b);
				}
				else {
					second.pop();
					second.push(b);
				}
				input_1.pop();
				continue;
			}
		}
	}
	int c = final.size();
	for (int i = 0; i < c; i++) {
		cout << final.top() << " ";
		final.pop();
	}
	// 4
	// 3 5 2 7
	return 0;
}*/
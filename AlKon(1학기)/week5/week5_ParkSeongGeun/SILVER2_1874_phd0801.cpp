#include <bits/stdc++.h>

using namespace std;

stack<int> p;
stack<int> q;
int input[100000];
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input[i];
	}
	vector<char> v;
	int cnt = 0;
	int count = 1;
	for (int i = 1; i <= N; i++) {
		p.push(i);
		v.push_back('+');
		while (!p.empty() && p.top() == input[cnt]) {
			p.pop();
			v.push_back('-');
			cnt++;
		}
	}
	if (!p.empty())cout << "NO";
	else {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << "\n";
		}
	}
	/*while (count <=N) {
		if (!p.empty()&&p.top() == input[cnt]) {
			v.push_back('-');
			p.pop();
			cnt++;
			continue;
		}
		p.push(count);
		v.push_back('+');
		count++;
	}*/
	return 0;
}
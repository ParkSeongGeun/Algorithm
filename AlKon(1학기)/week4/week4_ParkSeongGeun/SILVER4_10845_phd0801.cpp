#include <bits/stdc++.h>

using namespace std;

int N;
queue<int> q;
int main() {
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		if (str == "pop") {
			if (q.empty()) {
				cout << "-1"<<"\n";
			}
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (str == "size") {
			cout << q.size() << "\n";
		}
		else if (str == "empty") {
			if (q.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str == "front") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.front() << "\n";
			}
		}
		else if (str == "back") {
			if (q.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << q.back() << "\n";
			}
		}
		else {
			string p;
			for (int i = 5; i < str.size(); i++) {
				p += str[i];
			}
			stringstream ss(p);
			int n;
			ss >> n;
			q.push(n);
		}
	}
	return 0;
}
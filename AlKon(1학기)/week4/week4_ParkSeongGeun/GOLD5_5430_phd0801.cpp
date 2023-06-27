#include <bits/stdc++.h>	
#include <sstream>

using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		string p;//명령어
		cin >> p;
		int N; // 배열 내 숫자 개수
		cin >> N;
		deque<string> q;
		string arr;
		cin >> arr;
		arr.erase(arr.begin());
		arr.erase(arr.end() - 1);
		istringstream ss(arr);
		string stringBuffer;
		while (getline(ss, stringBuffer, ',')) {
			q.push_back(stringBuffer);
		}
		int count = 0;
		int check = 1;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				count++;
			}
			if (p[i] == 'D' && q.empty()) {
				cout << "error" << "\n";
				check = 0;
				break;
			}
			if (p[i] == 'D'&&!q.empty()) {
				if (count % 2 == 0) {
					q.pop_front();
				}
				else {
					q.pop_back();
				}
			}
		}
		if (count % 2 != 0&&check==1) {
			cout << "[";
			for (int j = q.size()-1; j>=0; j--) {
				cout << q[j];
				if (j != 0) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
		if (count % 2 == 0 && check==1) {
			cout << "[";
			for (int j = 0; j < q.size(); j++) {
				cout << q[j];
				if (j != q.size()-1) {
					cout << ",";
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}
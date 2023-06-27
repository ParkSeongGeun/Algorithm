#include <bits/stdc++.h>

using namespace std;

int R;
string User;
int N;
vector<string> v;

int main() {
	cin >> R;
	cin >> User;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string fr;
		cin >> fr;
		v.push_back(fr);
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < R; j++) {
			if (User[j] == 'R') {
				if (v[i][j] == 'R') {
					sum += 1;
				}
				else if (v[i][j] == 'S') {
					sum += 2;
				}
				else {
					;
				}
			}
			else if (User[j] == 'S') {
				if (v[i][j] == 'R') {
					;
				}
				else if (v[i][j] == 'S') {
					sum += 1;
				}
				else {
					sum += 2;
				}
			}
			else { // P
				if (v[i][j] == 'R') {
					sum += 2;
				}
				else if (v[i][j] == 'S') {
					;
				}
				else {
					sum += 1;
				}
			}
		}
	}
	cout << sum << "\n";
	int max = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < R; j++) {
			if (v[i][j] == 'R') {

			}
			else if (v[i][j] == 'S') {

			}
			else {

			}
		}
	}
	cout << max << "\n";
}
#define _CRT_SECURE_NO_WARNINGS	
#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int bonus = 1;
		int score=0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'O') {
				score += bonus;
				bonus++;
			}
			else {
				bonus = 1;
			}
		}
		cout << score << "\n";
	}
	return 0;
}
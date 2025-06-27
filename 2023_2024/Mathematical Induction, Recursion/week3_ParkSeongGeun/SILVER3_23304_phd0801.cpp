#include <bits/stdc++.h>

using namespace std;

string s;
int check;

void Check(string s, int size) {
	if (size == 1) {
		check = 1;
		return;
	}
	int a = size / 2;
	string s1;
	for (int i = 0; i < a; i++) {
		s1 += s[i];
	}
	string s2;
	for (int i = size - a; i < size; i++) {
		s2 += s[i];
	}
	if (s1 != s2) {
		check = 0;
		return;
	}
	Check(s1, a);
	Check(s2, a);
}
int main() {
	cin >> s;
	//cout << s.size() << "\n";
	Check(s, s.size());
	if (check == 1) {
		cout << "AKARAKA" << "\n";
	}
	else {
		cout << "IPSELENTI" << "\n";
	}
	return 0;
}
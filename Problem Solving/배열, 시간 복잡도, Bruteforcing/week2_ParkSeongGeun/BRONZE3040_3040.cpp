#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int PET[9];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> a;
		PET[i] = a;
		sum += a;
	}
	int check = 0;
	for (int i = 0; i < 8; i++) {
		if (check == 1) {
			break;
		}
		for (int j = i+1; j < 9; j++) {
			if (sum - (PET[i] + PET[j]) == 100) {
				PET[i] = 0;
				PET[j] = 0;
				check = 1;
				break;
			}
		}
	}
	for (int i = 0; i < 9; i++) {
		if (PET[i] == 0) {
			continue;
		}
		cout << PET[i] << "\n";
	}
	return 0;
}
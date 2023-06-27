#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

int student[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, C;
	cin >> N >>C;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		int k;
		cin >> k;
		student[i] = k;
	}
	for(int i=1;i<=C;i++){
		for (int j = 1; j <= N; j++) {
			if (i % student[j] == 0) {
				count++;
				break;
			}
		}
	}
	cout << count;
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>	

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	clock_t start = clock();
	int N;
	cin >> N;
	vector<int> v;
	for (int i = 1; i <=N ; i++) {
		v.push_back(i);
	}
	vector<int> permu;
	do {
		for (int i = 0; i < v.size(); i++) {
			permu.push_back(v[i]);
		}
	} while (next_permutation(v.begin(), v.end()));
	string s;
	vector<string> v2;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 1; j < s.size(); j++) {
			if (s[j] != s[j - 1]) {
				sum++;
			}
		}
		string s2="";
		s2 += s[0];
		s2 += s[s.size() - 1];
		v2.push_back(s2);
	}  
	int max_value = 0;
	for (int i = 0; i < permu.size(); i ++) {
		int cnt = 0;
		int change_1 = 0;
		int change_2 = 0;
		int not_change_1 = 0;
		int not_change_2 = 0;
		if (v2[permu[i] - 1] == "10") {
			change_1++;
		}
		else if (v2[permu[i] - 1] == "01") {
			change_2++;
		}
		else if (v2[permu[i] - 1] == "00") {
			not_change_1++;
		}
		else { // "11"
			not_change_2++;
		}
		int add = abs(change_1 - change_2);
		if (add > 1) {
			cnt += (add - 1);
		}
		if (not_change_1 == 0 && not_change_2==0&&change_1>0&&change_2>0) {
			cnt++;
		}
		if (max_value < cnt + sum) {
			max_value = cnt + sum;
		}
	}
	cout << max_value<< "\n";
	clock_t end = clock();
	printf("소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}

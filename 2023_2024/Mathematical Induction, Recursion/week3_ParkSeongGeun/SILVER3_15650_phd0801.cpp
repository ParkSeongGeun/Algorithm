#include <bits/stdc++.h>	

using namespace std;

int main() {
	// 조합의 아이디어 -> O
	// https://ansohxxn.github.io/algorithm/combination/#stl-prev_permutation%EC%9C%BC%EB%A1%9C-%EC%A1%B0%ED%95%A9-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0 참고
	int a, b;
	cin >> a >> b;
	vector<int> arr;
	for (int i = 1; i <= a; i++) {
		arr.push_back(i);
	}
	vector<bool> temp(arr.size(), false);
	for (int i = 0; i < b; i++) {
		temp[i] = true;
	}
	do {
		for (int i = 0; i < arr.size(); ++i) {
			if (temp[i]) {
				cout << arr[i] << " ";
			}
		}
		cout << "\n";
	} while (prev_permutation(temp.begin(), temp.end()));
	return 0;
}
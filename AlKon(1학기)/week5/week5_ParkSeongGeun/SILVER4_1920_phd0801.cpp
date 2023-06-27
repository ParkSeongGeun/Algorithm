#include <bits/stdc++.h>	

using namespace std;

int N;
int K;
int s1[100000];
int s2[100000];
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		s1[i] = a;
	}
	sort(s1, s1 + N);
	cin >> K;
	for (int i = 0; i < K; i++) {
		int b;
		cin >> b;
		if (binary_search(s1, s1+N, b)) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	return 0;
}
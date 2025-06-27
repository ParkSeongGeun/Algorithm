#include <bits/stdc++.h>

using namespace std;

int N, Q;
long long m2[100001];
long long m[100001];

unsigned long long go(int a, int b) {
	long long cnt2= m2[b] - m2[a-1];
	long long cnt = m[b] - m[a-1];
	return (pow(cnt, 2) - cnt2) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		m2[i] = pow(a,2) + m2[i - 1];
		m[i] = a + m[i - 1];
	}
	int a, b;
	for (int i = 1; i <= Q; i++) {
		cin >> a >> b;
		cout<< go(a, b) <<"\n";
	}
	return 0;
}
	
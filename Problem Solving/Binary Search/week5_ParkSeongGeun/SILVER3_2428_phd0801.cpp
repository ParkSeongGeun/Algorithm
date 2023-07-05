#include <bits/stdc++.h>	

using namespace std;

int N;
int F[100000];
long long sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> F[i];
	}
	sort(F, F + N);
	for (int i = 0; i < N; i++) {
		int k = lower_bound(F, F + i, F[i] * 0.9)-F;
		cout <<i<<"¹øÂ° -> "<< (i)-k << "\n";
		sum +=(i)-k;
	}
	cout << sum << "\n";
	return 0;
}
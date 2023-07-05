#include <bits/stdc++.h>

using namespace std;

string s;
int K, P, ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	if (s[0] == 'K') {
		K++;
	}
	else {
		P++;
	}
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == 'K') {
			K++;
			if(P){
				P--;
			}
		}
		else {
			P++;
			if (K) {
				K--;
			}
		}
		ans = max(ans, max(K, P));
	}
	cout << ans << "\n";
	return 0;
}
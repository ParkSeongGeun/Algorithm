#include <bits/stdc++.h>
#define MAX_NODE 100001
using namespace std;

int N;
vector<int> v[MAX_NODE];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 2; i <= N; i++) {
		cout << v[i][0] << "\n";
	}
	return 0;
}
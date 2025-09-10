#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll a, b, m, arr[30], total;
ll idx = 1;

vector<int>v;

int main() {
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
		
	for (int i = 0; i < m; i++) {
		total += arr[m-1-i] * idx;
		idx *= a;
	}

	ll tmp = 1;
	while (tmp <= total) tmp *= b;
	tmp /= b;

	while (tmp!=1) {
		v.push_back(total / tmp);
		total %= tmp;
		tmp /= b;
	}
	v.push_back(total / tmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> v; // (x,y)��ǥ �Է¹��� �� pair ��ü ���

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y; // x,y�Է� ��
		v.push_back(make_pair(x, y)); // pair��ü�� v�� push_back�ϱ�
	}
	sort(v.begin(), v.end()); // sort(v.begin(), v.end()) �� pair��ü���� x��ǥ�� ������ �˾Ƽ� y��ǥ�� ���ĵ�
	for (auto i = v.begin(); i != v.end(); i++) { // v.begin() ����� �ݺ��ڷ� �����ؼ� v.end()���� �ݺ��� ������
		cout << i->first << " " << i->second << "\n"; // *i.first == (i->first), *i.second == (i->second)
	}
	return 0;
}
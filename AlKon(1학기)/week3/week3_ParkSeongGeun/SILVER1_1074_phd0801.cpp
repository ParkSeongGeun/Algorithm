#include <bits/stdc++.h>	

using namespace std;

int n, r, c;
int ans;

// ��������� ������ Ǭ��
// �� �� ��Ȳ�� ��� Ǯ�̵Ǵ� �� ������ �� �ֱ� ������..
// -by �輺�� ������ -> �Ͼ��! ���� ������ �ȴٰ�!
void Z(int y, int x, int size) // ���� ���� �˰��� �Լ�(���� y, ���� x, ���� ����) �̷�������..����
{
	if (y == r && x == c) {
		cout << ans << '\n';
		return;
	} 
	// �����ϴ� ��и� ���� �����Ѵٸ�
	if (r < y + size && r >= y && c < x + size && c >= x) {
		// ��и� ���� �����Ѵٸ�
	   // ������ 4������� �ɰ� �ڿ� �ɰ� �κ��� ���� ��и����� ������ �����غ���
		// 1��и� Ž�� --> �ȴٰ�..����!
		Z(y, x, size / 2);
		// 2��и� Ž��
		Z(y, x + size / 2, size / 2);
		// 3��и� Ž��
		Z(y + size / 2, x, size / 2);
		// 4��и� Ž��
		Z(y + size / 2, x + size / 2, size / 2);
	}
	else { // ��и� ���� ���ٸ� �ű� �ڽ� ũ�⸸ŭ ans�� ���ϱ�
		ans += size * size;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> r >> c;
	Z(0, 0, pow(2, n));
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int arr[1000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int a;
	int index = 0;
	int max = 0;
	for (int i = 0; i < N; i++) {
		int check = 0;
		cin >> a;
		for (int j = 0; j < index; j++) {
			if (a == arr[j]) {
				check = 1;
				int value_1 = a * a;
				int sum_2 = 0;
				while (1) {
					if (value_1 == 0) {
						break;
					}
					sum_2 += value_1 % 10;
					value_1 = value_1 / 10;
				}
				if (sum_2 > max) {
					max = sum_2;
				}
				break;
			}
		}
		if (check != 1) {
			arr[index] = a;
			index++;
		}
	}
	for (int i = 0; i < index-1; i++) {
		for (int j = i+1; j < index; j++) {
			int value = arr[i] * arr[j];
			int sum = 0;
			while (1) {
				if (value == 0) {
					break;
				}
				sum+=value%10;
				value = value / 10;
			}
			//cout << sum << "\n";
			if (sum > max) {
				max = sum;	
			}
		}
	}
	cout << max;
	return 0;
}
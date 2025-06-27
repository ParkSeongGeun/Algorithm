#include <bits/stdc++.h>	

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a;
	cin >> a;
	int length = a.size();
	long long value = std::stoll(a);
	cout << value << "\n";
	long long search_start = value - length * 9;
	cout << search_start << "\n";
	for (long long i = search_start; i < value; i++) {
		long long num = i;
		long long sum = num;
		while (num > 0) {
			sum += num % 10;
			num /= 10;
		}
		if (sum == value) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
	return 0;
}
	//if (length > 3) {
	//	int sum = 0;
	//	for (int i = 0; i < a.size(); i++) {
	//		arr[i] = a[i] - '0';
	//		if (i < a.size() - 3) {
	//			sum += arr[i];
	//		}
	//	}
	//	if (arr[length - 3] * 100 + arr[length - 2] * 10 + arr[length - 1] > 162) {
	//		int result = arr[length - 3] * 100 + arr[length - 2] * 10 + arr[length - 1] - sum;
	//		for (int i = 0; i < 1000; i++) {
	//			int sum2 = 0;
	//			int value = i;
	//			sum2 += value % 10;
	//			value = (value - value % 10) / 10;
	//			sum2 += value % 10;
	//			value = (value - value % 10) / 10;
	//			sum2 += value;
	//			if (sum2 + i == result) {
	//				for (int i = 0; i < a.size() - 3; i++) {
	//					cout << arr[i];
	//				}
	//				cout << i << "\n";
	//				return 0;
	//			}
	//		}
	//		cout << "0";
	//	}
	//	else {
	//		int result2 = arr[length - 3] * 100 + arr[length - 2] * 10 + arr[length - 1]-sum;
	//		if (result2 < 0) {
	//			arr[length - 4]=arr[length-4]-1;
	//			for (int i = 0; i < 1000; i++) {
	//				int sum2 = arr[length-4]*1000;
	//				int sum3 = 0;
	//				int value = i;
	//				while (1) {
	//					sum3 += value % 10;
	//					value = (value - value % 10) / 10;
	//					if (value < 1) {
	//						break;
	//					}
	//					sum3 += value % 10;
	//					value = (value - value % 10) / 10;
	//					if (value < 1) {
	//						break;
	//					}
	//					sum3 += value;
	//					break;
	//				}
	//				if (sum+sum2+sum3+i-1 // -1은 arr[length-4]-1했기 때문에 그걸로 다 더해야 맞음
	//					== (arr[length - 4] + 1) * 1000 + arr[length - 3] * 100 + arr[length - 2] * 10 + arr[length - 1]) {
	//					for (int i = 0; i < a.size() - 3; i++) {
	//						cout << arr[i];
	//					}
	//					if (i < 100) {
	//						cout  <<"0"<< i;
	//					}
	//					else if(i<10) {
	//						cout << "00";
	//						cout << i;
	//					}
	//					else {
	//						cout << i;
	//					}
	//					return 0;
	//				}
	//			}
	//			cout << "0";
	//		}
	//		else {
	//			for (int i = 0; i < 1000; i++) {
	//				int sum2 = 0;
	//				int value = i;
	//				sum2 += value % 10;
	//				value = (value - value % 10) / 10;
	//				sum2 += value % 10;
	//				value = (value - value % 10) / 10;
	//				sum2 += value;
	//				if (sum2 + i == result2) {
	//					for (int i = 0; i < a.size() - 2; i++) {
	//						cout << arr[i];
	//					}
	//					cout << i << "\n";
	//					return 0;
	//				}
	//			}
	//			cout << "0";
	//		}
	//	}

	//}
	//else {
	//	for (int i = 0; i < 1000; i++) {
	//		int sum2 = 0;
	//		int value=i;
	//		sum2 += value % 10;
	//		value = (value - value % 10) / 10;
	//		sum2 += value % 10;
	//		value = (value - value % 10) / 10;
	//		sum2 += value;
	//		if (sum2+i== stoi(a)) {
	//			cout << i << "\n";
	//			return 0;
	//		}
	//	}
	//	cout << "0";
	//}	
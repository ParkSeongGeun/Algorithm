#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int i = 1;
	while (1) { // N위치에 해당하는 분자/분모의 합을 찾는 반보군
		N = N - i; // 배열이 1, 2, 3..칸씩 이뤄져있으므로 
		// 만약 N이 8이라면 N의 분자/분모의 합은
		// N-1-2-3...
		if (N <= 0) { // N-1-2-3-4<0 이 되는 첫 위치이므로 
			// N의 분모+분자의 합은 5이다.
			N = N + i;// 이때 N의 값은 -2가 되므로 다시 N을 i만큼 더해주면 +2가 되고
			break;    // 이때 N은 분모+분자 배열 중 몇 번째에 위치하는 지를 나타냄
			// 이때 i+1이 분모+분자 값
		}
		i++;
	}
	//cout << "N 위치에 해당하는 <분자+분모> 값 -> "<<i+1 << endl;
	//cout << "N의 값 => " << N << "\n";

	if (i % 2 == 1) { // 이때 i가 홀수, 짝수 인지에 따라 조건을 나눠서
		cout << i + 1 - N << "/" << N << "\n"; // 분자/분모의 값을 출력
	}
	else {
		cout << N << "/" << i + 1 - N << "\n";
	}

	return 0;
}
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int count[10001] = {0};  // 1~10,000 범위
    
    // 입력받으면서 바로 카운트 (배열에 저장 안 함!)
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        count[num]++;
    }
    
    // 카운트한 만큼 출력
    for(int i = 1; i <= 10000; i++) {
        for(int j = 0; j < count[i]; j++) {
            cout << i << '\n';
        }
    }
    
    return 0;
}
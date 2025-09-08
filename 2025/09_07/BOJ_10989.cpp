#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int count[10001] = {0};

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
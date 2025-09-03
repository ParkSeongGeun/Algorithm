#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int arr[1001];
int dp_up[1001];
int dp_down[1001];

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        dp_up[i] = 1;  // 최소 길이는 1 (자기 혼자)
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                dp_up[i] = max(dp_up[i], dp_up[j] + 1);
            }
        }
    }
    
    for(int i = N-1; i >= 0; i--) {
        for(int j = i+1; j < N; j++) {
            if(arr[i] > arr[j]) {
                dp_down[i] = max(dp_down[i], dp_down[j] + 1);
            }
        }
    }

    // for(int i=0;i<N;i++){
    //     cout << dp_up[i] << " ";
    // }
    // cout << "\n";


    // for(int i=0;i<N;i++){
    //     cout << dp_down[i] << " ";
    // }
    // cout << "\n";

    int result = 0;
    for(int i = 0; i < N; i++) {
        result = max(result, dp_up[i] + dp_down[i]);
    }
    cout << result << "\n";

    return 0;
}
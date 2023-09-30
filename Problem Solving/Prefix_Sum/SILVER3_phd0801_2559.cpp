#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
int arr[100001];
int res[100001];
int max_value;

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        cin >> arr[i];
        // for(int j=i;j>=i-(K-1);j--){
        //     if(j<0){
        //         break;
        //     }
        //     res[i] += arr[j];
        // }
    }
    for(int i=0;i<K;i++){
        res[K-1] += arr[i];
    }
    // for(int i=0;i<N;i++){
    //     cout << res[i] << " ";
    // }
    // cout << "\n";
    for(int i=K;i<N;i++){
        res[i] = res[i-1] + arr[i] - arr[i-K];
    }
    // for(int i=0;i<N;i++){
    //     cout << res[i] << " ";
    // }
    // cout << "\n";
    sort(res+K-1, res + N);
    cout << res[N-1] << "\n";
    return 0;
}
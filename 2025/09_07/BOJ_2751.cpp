#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    const int OFFSET = 1000000;
    const int MAX_RANGE = 2000001;

    bool exists[MAX_RANGE] = {false};

    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        exists[num + OFFSET] = true;
    }

    for(int i=0;i<MAX_RANGE;i++){
        if(exists[i]) {
            cout << (i - OFFSET) << "\n";
        }
    }

    return 0;
}

// void merge(vector<int>& arr, int left, int mid, int right) {
//     int n1 = mid-left+1;
//     int n2 = right-mid;

//     // 임시 배열 생성
//     vector<int> L(n1), R(n2);

//     // 데이터 복사
//     for(int i=0;i<n1;i++){
//         L[i] = arr[left+i];
//     }
//     for(int j=0;j<n2;j++){
//         R[j] = arr[mid+1+j];
//     }

//     // 병합 과정
//     int i=0, j=0, k=left;
//     while(i < n1 && j < n2) {
//         if(L[i] <= R[j]){
//             arr[k++] = L[i++];
//         } else {
//             arr[k++] = R[j++];
//         }
//     }

//     // 남은 원소들 복사
//     while(i<n1) arr[k++] = L[i++];
//     while(j<n2) arr[k++] = R[j++];
// }

// void mergeSort(vector<int>& arr, int left, int right) {
//     if (left < right) {
//         int mid = (right + left) / 2;
//         mergeSort(arr, left, mid);      // 왼쪽 절반 정렬
//         mergeSort(arr, mid+1, right);   // 오른쪽 절반 정렬
//         merge(arr, left, mid, right);   // 병합
//     }
// }

// int main() {
//     int N;
//     cin >> N;

//     vector<int> arr(N);
//     for(int i=0;i<N;i++){
//         cin >> arr[i];
//     }

//     mergeSort(arr, 0, N-1);

//     for(int i=0;i<N;i++){
//         cout << arr[i] << "\n";
//     }

//     return 0;
// }
// int N;
// int arr[1000001];

// int main() {
//     cin >> N;
//     for(int i=0;i<N;i++){
//         cin >> arr[i];
//     }

//     sort(arr, arr + N);

//     for(int i=0;i<N;i++){
//         cout << arr[i] << "\n";
//     }
//     return 0;
// }
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

int N;
int arr[100001];

ll res;
ll sum;

void    go(){
    if (sum + 1 < arr[N-1])
        cout << 2 * sum + 1 <<"\n";
    else
        cout << sum + arr[N-1] << "\n";
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    for(int i=0;i<N-1;i++)
    {
        sum += arr[i];
    }
    go();
    return 0;
}
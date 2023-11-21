#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[11];
int T, N;

ll go(int start){
    if(arr[start] != 0){
        return arr[start];
    }
    // if arr[start] = 0
    if(arr[start-3]==0){
        go(start-3);
    }
    if(arr[start-2]==0){
        go(start-2);
    }
    if(arr[start-1]==0){
        go(start-1);
    }
    arr[start] = arr[start-1]+arr[start-2]+arr[start-3];
    return arr[start];
}


int main(){
    cin >> T;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i=0;i<T;i++){
        cin >> N;
        cout << go(N) << "\n";
    }
}
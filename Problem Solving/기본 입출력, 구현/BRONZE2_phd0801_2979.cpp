#include <bits/stdc++.h>

using namespace std;

int arr[101];
int one, two, three;
int start, ending;
int res;

int main(){
    cin >> one >> two >> three;
    for(int i=0;i<3;i++){
        cin >> start >> ending;
        for(int i=start; i<ending; i++){
            arr[i]++;
        }
    }
    for(int i=1;i<101;i++){
        if(arr[i]==1){
            res += 1 * one;
        }
        else if(arr[i]==2){
            res += 2 * two;
        }
        else if(arr[i]==3){
            res += 3 * three;
        }
    }
    cout << res << "\n";
    return 0;
}
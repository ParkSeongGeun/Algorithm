#include <iostream>
#include <algorithm>

using namespace std;

int sum;
int N, S, res;
int arr[21];

void dfs(int i, int sum){
    if(i==N) 
        return ;
    if(sum+arr[i]==S){
        res++;
    }
    dfs(i+1, sum);
    dfs(i+1, sum+arr[i]);
}

int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    dfs(0, 0);
    cout << res << "\n";
    return 0;
}
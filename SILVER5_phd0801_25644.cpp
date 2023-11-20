#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> v;
int cnt = -1;
int ans;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a); 
    }
    for(int i=N-1;i>=0;i--){
        if(cnt < v[i]){
            cnt = v[i];
        }
        ans = max(ans, cnt - v[i]);
    }
    cout << ans << "\n";
    return 0;
}
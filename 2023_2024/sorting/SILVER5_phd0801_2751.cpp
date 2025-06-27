#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cout << v[0] <<"\n";
    for(int i=1;i<N;i++){
        if(v[i-1] == v[i]){
            continue;
        }
        else{
            cout << v[i] << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int N, res;
string s;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s;
        stack<char> c;
        for(char a : s){
            if(c.size() != 0 && c.top() == a){
                c.pop();
            }
            else{
                c.push(a);
            }
        }
        if(c.size() == 0){
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
string s;

int go(string s){
    stack<char> s1;
    for(int i=0;i<s.size();i++){
        if(s1.empty()){
            if(s[i]==')'){
                return 0;
            }
            else{
                s1.push(s[i]);
            }
        }
        else{
            if(s[i]==')'){
                s1.pop();
            }
            else{
                s1.push(s[i]);
            }
        }
    }
    if(s1.empty()){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        if(go(s)==0){
            cout << "NO" <<"\n";
        }
        else{
            cout << "YES" << "\n";
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    getline(cin, s);
    for(int i=0; i<s.length(); i++){
        if('A' <= s[i] && s[i] <= 'Z'){
            s[i] = (char)((s[i] -'A' + 13)%26) + 'A'; 
        }
        else if('a' <= s[i] && s[i] <= 'z'){
            s[i] = (char)((s[i] -'a' + 13)%26) + 'a'; 
        }
        else {
            continue;
        }
    }
    for(char c : s){
        cout << c;
    }
    return 0;
}
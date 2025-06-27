#include <bits/stdc++.h>

using namespace std;

string s;

int main(){
    cin >> s;
    int l = 0;
    int r = s.length()-1;
    while(l<r){
        if(l==r){
            break;
        }
        if(s[l]!=s[r]){
            cout << '0' << "\n";
            return 0;
        }
        l++;
        r--;
    }
    cout << '1' << "\n";
    return 0;
}
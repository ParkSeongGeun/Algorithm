#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;

int find_len(string s, int i, int j){
    if(i>j){
        return 0;
    }
    if(i==j){
        return 1;
    }
    if(s[i]==s[j]){
        return (2+find_len(s, i+1, j-1));
    }
    else{
        return max(find_len(s, i+1, j), find_len(s, i, j-1));
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> s;
    cout << find_len(s, 0, s.length()-1) << "\n";
    return 0;
}
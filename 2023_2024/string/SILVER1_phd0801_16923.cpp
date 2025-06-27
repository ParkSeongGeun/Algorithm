#include <iostream>
#include <string>

using namespace std;

string s;
int len;
char input[26];
int check[26];

//abcdefghijklmnopqrstuvwxyz
int main(){
    cin >> s;
    for(int i=0;i<s.length();i++){
        input[i] = s[i];
        check[input[i]-'a'] = i+1;
    }
    if(s.length()==26){
        if(next_permutation(input, input+27)==true){
            cout << input << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }
    else{
        for(int i=0;i<26;i++){
            if(check[i]==0){
                char c = (i+'a');
                s += c;
                cout << s << "\n";
                break;
            }
        }
    }
    return 0;
}
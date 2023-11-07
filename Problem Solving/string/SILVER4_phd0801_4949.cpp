#include <iostream>
#include <string>
#include <stack>

using namespace std;

string s;

int main() {
    while (1) {
        int check=0;
        stack<char> s1;
        getline(cin, s);
        if(s=="."){
            break;
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i]=='('||s[i]=='['){
                s1.push(s[i]);
            }
            if(s[i]==')'){
                if(s1.empty()||s1.top()!='('){
                    check = 1;
                }
                else{
                    s1.pop();
                }
            }
            if(s[i]==']'){
                if(s1.empty()||s1.top()!='['){
                    check = 1;
                }
                else{
                    s1.pop();
                }
            }
        }
        if(check==0&&s1.empty()){
            cout << "yes" << "\n";
        }
        else{
            cout << "no" << "\n";
        }
    }
    return 0;
}
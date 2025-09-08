#include <iostream>
#include <stack>

using namespace std;

string s;
stack<char> stk;

int main() {
    cin >> s;

    int res = 0;
    
    for(int i=0;i<s.length();i++){
        char c = s[i];
        
        if(c=='(') {
            stk.push(c);
        } else {
            stk.pop();
            if (s[i-1] == '(') {
                res += stk.size();
            } else {
                res++;
            }
        }
        
    }

    cout << res << "\n";
    return 0;
}
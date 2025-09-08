#include <iostream>
#include <stack>

using namespace std;

int n;
stack<int> stk;

int main() {
    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;

        if(s=="push") {
            int cnt;
            cin >> cnt;
            stk.push(cnt);
        } else if (s=="pop") {
            if (stk.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << stk.top() << "\n";
                stk.pop();
            }
        } else if (s=="size") {
            cout << stk.size() << "\n";
        } else if (s=="empty") {
            if (stk.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s=="top") {
            if (stk.empty()) {
                cout << -1 << "\n";
            } else {
                cout << stk.top() << "\n";
            }
        }
    }
}
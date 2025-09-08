#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>

using namespace std;

stack<char> l;
stack<char> r;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    string s;
    cin >> s;

    int n;
    cin >> n;

    int cursor = s.length();

    for(int i=0;i<s.length();i++){
        l.push(s[i]);
    }

    for(int i=0;i<n;i++){
        string cur;
        cin >> cur;
        if (cur == "P") {
            char c;
            cin >> c;
            l.push(c);
        } else if (cur == "L") {
            // 커서를 왼쪽으로 한 칸
            if (!l.empty()) {
                char c = l.top();
                l.pop();
                r.push(c);
            }
        } else if (cur == "D") {
            // 커서를 오른쪽으로 한 칸
            if (!r.empty()) {
                char c = r.top();
                r.pop();
                l.push(c);
            }
        } else if (cur == "B") {
            // 커서 왼쪽에 있는 문자를 삭제
            if (!l.empty()) {
                l.pop();
            }
        }
    }

    vector<char> v1(l.size());
    vector<char> v2(r.size());
    int cnt1 = 0;
    while(!l.empty()) {
        v1[cnt1] = l.top();
        l.pop();
        cnt1++;
    }

    int cnt2 = 0;
    while(!r.empty()) {
        v2[cnt2] = r.top();
        r.pop();
        cnt2++;
    }

    reverse(v1.begin(), v1.end());

    for(char c : v1) {
        cout << c;
    }
    for(char c : v2) {
        cout << c;
    }
    cout << "\n";
    return 0;
}
#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int> dq;

int main() {
    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;

        int cnt;
        if (s=="push_front") {
            cin >> cnt;
            dq.push_front(cnt);
        } else if (s=="push_back") {
            cin >> cnt;
            dq.push_back(cnt);
        } else if (s=="pop_front") {
            if (dq.empty()) {
                cout << -1 << "\n";
            } else {
                int b = dq.front();
                cout << b << "\n";
                dq.pop_front();
            }
        } else if (s=="pop_back") {
            if (dq.empty()) {
                cout << -1 << "\n";
            } else {
                int b = dq.back();
                cout << b << "\n";
                dq.pop_back();
            }
        } else if (s=="size") {
            cout << dq.size() << "\n";
        } else if (s=="empty") {
            if (dq.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s=="front") {
            if (dq.empty()) {
                cout << -1 << "\n";
            } else {
                cout << dq.front() << "\n";
            }
        } else if (s=="back") {
            if (dq.empty()) {
                cout << -1 << "\n";
            } else {
                cout << dq.back() << "\n";
            }
        }
    }

    return 0;
}
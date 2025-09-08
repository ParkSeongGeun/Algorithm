#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

int main() {
    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;

        if (s=="push") {
            int cnt;
            cin >> cnt;
            q.push(cnt);
        } else if (s=="pop") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                int b = q.front();
                cout << b << "\n";
                q.pop();
            }
        } else if (s=="size") {
            cout << q.size() << "\n";
        } else if (s=="empty") {
            if (q.empty()) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if (s=="front") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.front() << "\n";
            }
        } else if (s=="back") {
            if (q.empty()) {
                cout << -1 << "\n";
            } else {
                cout << q.back() << "\n";
            }
        }
    }

    return 0;
}
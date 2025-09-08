#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    string s;

    vector<string> v;

    cin >> s;

    for(int i=0;i<s.length();i++){
        string subs = s.substr(i, s.length());
        v.push_back(subs);
    }

    sort(v.begin(), v.end());

    for(string s: v) {
        cout << s << "\n";
    }

    return 0;
}
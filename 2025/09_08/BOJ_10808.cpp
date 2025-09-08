#include <iostream>

using namespace std;

int arr[26];

int main() {
    string s;
    cin >> s;

    for(int i=0;i<s.length();i++){
        arr[s[i] - 'a']++;
    }

    for(int i:arr) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
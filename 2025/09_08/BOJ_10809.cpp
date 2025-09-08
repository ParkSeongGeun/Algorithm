#include <iostream>

using namespace std;

int arr[26];

int main() {
    string s;

    cin >> s;

    for(int i=0;i<26;i++){
        arr[i] = -1;
    }

    for(int i=0;i<26;i++){
        for(int j=0;j<s.length();j++){
            if(i == s[j] - 'a') {
                if (arr[i] == -1) {
                    arr[i] = j;
                }
            }
        }
    }

    for(int i:arr) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
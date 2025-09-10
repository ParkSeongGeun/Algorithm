#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string s;
string res;

int main() {
    cin >> s;

    string arr[8] = {
        "000", "001", "010", "011",
        "100", "101", "110", "111"
    };

    string arr2[8] = {
        "0", "1", "10", "11",
        "100", "101", "110", "111"
    };

    for(int i=0;i<s.length();i++){
        for(int j=0;j<8;j++){
            if (j == s[i] - '0') {
                if (i==0) {
                    res += arr2[j];
                } else {
                    res += arr[j];
                }
            }
        }
    }

    cout << res << "\n";

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

string s;

int main() {
    cin >> s;

    string arr[8] = {
        "000", "001",
        "010", "011",
        "100", "101",
        "110", "111"
    };

    int i;
    vector<int> v;
    for(i=s.length()-1;i>=0;i-=3) {
        // cout << "i: " << i << "\n";
        if(i-2<0){
            break;
        }

        string k = s.substr(i-2, 3);

        for(int j=0;j<8;j++){
            if (arr[j] == k) {
                v.push_back(j);
            }
        }
    }

    if (i >= 0) {
        for(int j=0;j<8;j++){
            string k = s.substr(0, i + 1);
            if (stoi(arr[j]) == stoi(k)){
                v.push_back(j);
            }
        }
    }

    reverse(v.begin(), v.end());
    for(int i:v){
        cout << i;
    }
    cout << "\n";
    return 0;
}
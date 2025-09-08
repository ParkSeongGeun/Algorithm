#include <iostream>

using namespace std;

int main() {
    string line;
    while (getline(cin, line) && !line.empty()) {
        int arr[4] = {0, 0, 0, 0};
        for(int i=0;i<line.length();i++){
            if ('a'<= line[i] && line[i] <= 'z') {
                arr[0]++;
            } else if ('A' <= line[i] && line[i] <= 'Z') {
                arr[1]++;
            } else if ('0' <= line[i] && line[i] <= '9') {
                arr[2]++;
            } else if (line[i] == ' ') {
                arr[3]++;
            }
        }
        for(int i:arr) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
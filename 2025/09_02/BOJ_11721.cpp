#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;
    for(int i=0;i<input.length();i++){
        cout << input[i];
        if((i+1) % 10 == 0 && i > 0) {
            cout << "\n";
        }
    }
    return 0;
}
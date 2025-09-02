#include <iostream>

using namespace std;

int main() {
    int c;
    string input;

    cin >> c;
    for(int i=0;i<c;i++){
        cin >> input;
        auto idx = input.find(',');
        int a = stoi(input.substr(0, idx));
        int b = stoi(input.substr(idx + 1));
        cout << a + b << "\n";
    }

    return 0;
}
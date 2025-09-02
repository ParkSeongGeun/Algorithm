#include <iostream>

using namespace std;

int main() {
    int sum = 0;
    int a;
    cin >> a;
    for(int i=0;i<a;i++){
        char c;
        cin >> c;
        sum += c - '0';
    }

    cout << sum << "\n";
    return 0;
}
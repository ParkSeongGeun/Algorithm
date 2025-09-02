#include <iostream>

using namespace std;

int main() {
    int a;

    cin >> a;
    for(int i=1;i<=a;i++){
        for(int j=i;j<a;j++){
            cout << " ";
        }
        if (i==a) {
            for(int j=1;j<2*i;j++){
                cout << "*";
            }
        } else if (i==1){
            for(int j=0;j<i;j++){
                cout << "* ";
            }
        } else {
            cout << "*";
            for(int j=1;j<i*2 - 2;j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int w, h;
int p, q;
int t;
int dx = 1, dy = 1;

int main(){
    cin >> w >> h;
    cin >> p >> q;
    cin >> t;
    if((p+t)/w%2==0)
        p = (p+t)%w;
    else
        p = w - (p+t)%w;
    if((q+t)/h%2==0)
        q = (q+t) %h;
    else
        q = h-(q+t)%h;
    cout << p << " " << q <<"\n";
    return 0;
}


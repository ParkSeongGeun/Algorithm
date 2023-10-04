#include <iostream>
#include <algorithm>

using namespace std;
long long N;
long long res;
long long k = 1;

int main(){
    cin >> N;
    if(N==1)
    {
        cout << 1 << "\n";
        return 0;
    }
    while(1)
    {
        res = res + k;
        if(res > N)
            break;
        k++;
    }
    cout << k - 1 << "\n";
    return 0;
}
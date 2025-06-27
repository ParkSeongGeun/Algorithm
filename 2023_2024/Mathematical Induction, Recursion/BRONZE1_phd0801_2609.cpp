#include <iostream>

using namespace std;

int p, q;

int find_max(int a, int b)
{
    if(a%b==0)
    {
        return (b);
    }
    return find_max(b, a % b);
}
int main(){
    cin >> p >> q;
    int a = min(p, q);
    int b = max(p, q);
    cout << find_max(b, a) <<"\n";
    cout << p * q /find_max(b,a);
    return 0;
}
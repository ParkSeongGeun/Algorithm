#include <iostream>
#include <algorithm>
#include <vector>
#define ull unsigned long long

using namespace std;

ull a,b,c;
ull ans=1;

void multi(ull *a, ull *b)
{
    *a = ((*a) * (*b))%c;
}

int main()
{
    cin>>a>>b>>c;
    while(b>0)
    {
        if(b%2==1)
        {
            multi(&ans,&a);
        }
        multi(&a, &a);
        b /= 2;
    }
    cout << ans << "\n";
    return 0;
}
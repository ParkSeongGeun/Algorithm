#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int N;
ll temp;

ll gcd(ll a,ll b)
{
    if (a % b==0)
        return b;
    else
        return gcd(b, a % b);
}

ll result(ll a, ll b)
{
    ll c = gcd(a, b);
    ll cnt = (a * b) / c;
    return (cnt);
}

ll go(ll temp)
{
    ll first = result(result(temp-2, temp-1), temp);
    ll second = result(result(temp-3, temp-1), temp);
    ll third = result(result(temp-3, temp-2), temp-1);
    ll fourth = result(result(temp-3, temp-2), temp);
    ll res1 = max(first, second);
    ll res2 = max(third, fourth);
    return (res1 > res2) ? res1 : res2;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> temp;
        cout << go(temp) <<"\n";
    }
}
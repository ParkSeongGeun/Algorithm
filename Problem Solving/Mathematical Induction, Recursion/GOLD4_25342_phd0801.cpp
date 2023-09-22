#include <iostream>
#include <algorithm>

using namespace std;

int N;
int temp;

unsigned long long gcd(int a, int b)
{
    if (b==0)
        return a;
    else
        return gcd(b, a % b);
}

unsigned long long result(int a, int b, int c)
{
    unsigned long long d = gcd(a, b);
    unsigned long long cnt = (a * b) / d;
    //cout << cnt<<"\n";
    unsigned long long max_val = gcd(cnt, c);
    //cout << (cnt *c)/max_val <<"\n";
    return (cnt * c / max_val);
}

unsigned long long go(int temp)
{
    unsigned long long first = result(temp-2, temp-1, temp);
    unsigned long long second = result(temp-3, temp-1, temp);
    unsigned long long third = result(temp-3, temp-2, temp-1);
    unsigned long long fourth = result(temp-3, temp-2, temp);
    unsigned long long res1 = max(first, second);
    unsigned long long res2 = max(third, fourth);
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
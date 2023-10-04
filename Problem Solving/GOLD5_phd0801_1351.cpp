#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <vector>
#define ull unsigned long long

using namespace std;

ull N, P, Q;
unordered_map<ull, ull> m;

ull go(ull N, ull P, ull Q)
{
    if(N==0)
    {
        return 1;
    }
    unordered_map<ull, ull>::iterator iter;
    iter = m.find(N);
    if(iter != m.end())
    {
        return m[N];
    }
    m[N] = go(N/P, P, Q) + go(N/Q, P, Q);
    return m[N];
}

int main(){
    cin >> N >> P >> Q;
    m[0]=1;
    cout << go(N, P, Q);
    return 0;
}
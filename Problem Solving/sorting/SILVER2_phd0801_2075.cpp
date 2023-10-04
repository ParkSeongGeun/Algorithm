#include <iostream>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

vector<ll> v;
int N;
ll num;

void change_value(ll *a, ll *b)
{
    ll temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int start, int end)
{
    int pivot = v[end];
    int i = (start-1);
    for(int j=start;j<=end-1;j++)
    {
        if(v[j]<=pivot)
        {
            i++;
            change_value(&v[i], &v[j]);
        }
    }
    change_value(&v[i+1], &v[end]);
    return (i+1);
}

void quick_sort(int start, int end)
{
    if(start < end)
    {
        int pivot = partition(start, end);
        quick_sort(start, pivot-1);
        quick_sort(pivot+1, end);
    }
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    v.assign(3, 0);
    for(int i=0;i<3;i++)
    {
        cin >> num;
        v[i] = num;
    }
    quick_sort(0, 2);
    for(auto k = v.begin();k!=v.end();k++)
    {
        cout << *k << " ";
    }
    cout << "\n";
    return 0;
}
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int N;
vector< pair<int, string> > p;

bool compare(const pair<int, string> &a, const pair<int, string> &b)
{
    return a.first < b.first;
}
int main(){
    cin >> N;
    int a;
    string b;
    for(int i = 0; i < N; i++)
    {
        cin >> a;
        cin >> b;
        p.push_back(make_pair(a, b));
    }
    stable_sort(p.begin(), p.end(), compare);
    for(int i = 0; i < N; i++)
    {
        cout << p[i].first << " " << p[i].second << "\n";
    }
    return 0;
}
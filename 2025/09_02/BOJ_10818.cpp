#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    int a;
    cin >> a;

    for(int i=0;i<a;i++){
        int b;
        cin >> b;
        v.push_back(b);
    }

    sort(v.begin(), v.end());

    cout << v[0] << " " << v[v.size()-1] << "\n";
    
    return 0;
}
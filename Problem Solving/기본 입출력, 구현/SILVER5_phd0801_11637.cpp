#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int cnt;
int a;

int main(){
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> cnt;
        vector< pair<int, int> > v;
        for(int i=1;i<=cnt;i++){
            cin >> a;
            v.push_back(make_pair(a, i));
        }
        sort(v.begin(), v.end());
        if(v[cnt-1].first==v[cnt-2].first){
            cout << "no winner" <<"\n";
        }
        else{
            int sum = 0;
            for(int i=0;i<cnt-1;i++){
                sum += v[i].first;
            }
            if(v[cnt-1].first>sum){
                cout << "majority winner " << v[cnt-1].second << "\n";
            }
            else{
                cout << "minority winner " << v[cnt-1].second << "\n";
            }
        }
    }
}
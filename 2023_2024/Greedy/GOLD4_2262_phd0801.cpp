#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int input_first;
int res;
//vector< pair<int, bool> > v;
vector<int> v;

void    go()
{
    while(v.size() > 3)
    {
        // find max_value;
        int max_value = 0;
        int max_index = 0;
        for(int i = 1 ; i <= (int)v.size() - 2 ; i++){
            if (v[i] > max_value){
                max_value = v[i];
                max_index = i;
            }
        }
        //cout << max_value << "\n";
        // max_value의 index를 찾은 후 양 옆을 검사
        int left, right;
        left = v[max_index-1];
        right = v[max_index+1];
        int cnt = max(left, right);
        res = res + (v[max_index] - cnt);
        //cout << "res값 변화 : " << res <<"\n";
        v.erase(v.begin() + max_index);
    }
}

int main(){
    cin >> N;
    v.push_back(0);
    for (int i=1;i<=N;i++)
    {
        cin >> input_first;
        v.push_back(input_first);
    }
    v.push_back(0);
    go();
    cout << res << "\n";
    return 0;
}
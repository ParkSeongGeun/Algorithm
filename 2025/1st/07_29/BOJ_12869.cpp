#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int N;
int ans = 100000000;
vector<int> v;
vector<int> attack(3);
map<vector<int>, int> memo;

int go(vector<int> param, int depth) {

    if (memo.find(param) != memo.end()) {
        return memo[param];
    }

    if (depth >= ans) {
        return 1000000;
    }

    bool flag = false;

    for(int i : param) {
        if (i > 0) {
            flag = true;
        }
    }

    if (!flag) {
        memo[param] = depth;
        if (ans > depth) {
            ans = depth;
        }
        return depth;
    }

    vector<int> idx(N);

    for(int i=0;i<N;i++){
        idx[i] = i;
    }

    int minResult = 1000000;  // 이 상태에서의 최소값
    
    do {
        vector<int> temp = param;
        for(int i=0;i<N;i++){
            temp[idx[i]] -= attack[i];
        }
        sort(temp.begin(), temp.end());
        
        int result = go(temp, depth + 1);
        minResult = min(minResult, result);
        
    } while(next_permutation(idx.begin(), idx.end()));
    
    memo[param] = minResult;  // 결과 저장
    return minResult;
}

int main() {
    cin >> N;

    attack[0] = 9;
    attack[1] = 3;
    attack[2] = 1;

    for(int i=0;i<N;i++){
        int cnt;
        cin >> cnt;
        v.push_back(cnt);
    }

    sort(v.begin(), v.end());

    cout << go(v, 0) <<  "\n";

    return 0;
}
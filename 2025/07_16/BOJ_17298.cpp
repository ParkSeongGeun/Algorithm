#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> ans;

stack<int> stk;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    v.resize(N);
    ans.resize(N);

    for(int i = 0; i<N;i++){
        cin >> v[i];
        ans[i] = 0;
    }

    for(int i = N-1; i>=0;i--) {
        // 현재 원소보다 작거나 같은 애들은 제거
        while(!stk.empty() && stk.top() <= v[i]) {
            stk.pop();
        }

        // 비어있으면 -1
        if (stk.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = stk.top();
        }

        stk.push(v[i]);
    }

    for(int i : ans) {
        cout << i << " ";
    }

    return 0;
}
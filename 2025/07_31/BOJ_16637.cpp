#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
string expression;
vector<int> numbers;
vector<char> operators;
int ans = INT_MIN;

int calculate(int a, char op, int b) {
    switch(op) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
    }
    return 0;
}

void solve(int idx, int cur, char prev, int bracketIdx) {
    if (idx >= numbers.size()) {
        ans = max(ans, cur);
        return;
    }

    // 괄호 X - 그냥 계산
    int val = calculate(cur, prev, numbers[idx]);

    if (idx < operators.size()) {
        solve(idx+1, val, operators[idx], bracketIdx);
    } else {
        ans = max(ans, val);
    }

    // 괄호 O - 조건 체크
    if (idx + 1 < numbers.size() && 
        idx < operators.size() && 
        idx > bracketIdx) {
        int bracketVal = calculate(numbers[idx], operators[idx], numbers[idx+1]);
        int val2 = calculate(cur, prev, bracketVal);

        if (idx + 1 < operators.size()) {
            solve(idx+2, val2, operators[idx+1], idx+1);
        } else {
            ans = max(ans, val2);
        }
    }
}

int main() {
    cin >> N;
    cin >> expression;

    for(int i=0; i<N; i++){
        if (i % 2 == 0){
            numbers.push_back(expression[i]-'0');
        } else {
            operators.push_back(expression[i]);
        }
    }

    solve(0, 0, '+', -1);
    cout << ans << "\n";

    return 0;
}
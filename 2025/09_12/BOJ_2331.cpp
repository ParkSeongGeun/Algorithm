#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define m 240000

int a, p;
int check[m];

void dfs(int num) {
    check[num]++;

    if (check[num] == 3) {
        return;
    }

    int next = 0;
    while(num) {
        next += pow(num% 10, p);
        num /= 10;
    }
    dfs(next);
}

int main() {
    cin >> a >> p;

    dfs(a);
    int cnt = 0;
    for(int i=1;i<m;i++){
        if (check[i] == 1) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
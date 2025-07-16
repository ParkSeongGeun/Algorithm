#include <iostream>
#include <vector>

using namespace std;

int n, k, res, root;
vector<int> v[51];

int dfs(int node) {
    if (node == k) {
        return -1;
    }
    
    int child = 0;

    for (int i=0;i<v[node].size();i++){
        int temp = dfs(v[node][i]);
        if (temp != -1) {
            child++;
        }
    }

    if (child == 0) {
        res++;
    }

    return 0;
}

int main() {
    cin >> n;

    for(int i=0;i<n;i++){
        int cnt;
        cin >> cnt;

        if (cnt == -1) {
            root = i;
        } else {
            v[cnt].push_back(i);
        }
    }
    cin >> k;

    if (root == k) {
        cout << 0 << "\n";
        return 0;
    }


    dfs(root);
    cout << res << "\n";
    return 0;
}
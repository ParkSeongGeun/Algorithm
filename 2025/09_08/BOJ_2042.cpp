#include <iostream>
#include <vector>
using namespace std;

vector<long long> tree;
int n, m, k;

void build(vector<long long>& arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(arr, 2*node, start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, long long val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(2*node, start, mid, idx, val);
        } else {
            update(2*node+1, mid+1, end, idx, val);
        }
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    
    int mid = (start + end) / 2;
    return query(2*node, start, mid, l, r) + 
           query(2*node+1, mid+1, end, l, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    vector<long long> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    tree.resize(4 * n);
    build(arr, 1, 0, n-1);
    
    for(int i = 0; i < m + k; i++) {
        int a;
        cin >> a;
        
        if(a == 1) { // 업데이트
            int b;
            long long c;
            cin >> b >> c;
            update(1, 0, n-1, b-1, c); // 1-based → 0-based
        } else { // 쿼리
            int b, c;
            cin >> b >> c;
            cout << query(1, 0, n-1, b-1, c-1) << "\n"; // 1-based → 0-based
        }
    }
    
    return 0;
}
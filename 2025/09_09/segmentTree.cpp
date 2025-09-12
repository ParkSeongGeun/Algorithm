#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

vector<ll> tree;
int n;

ll getTreeSize(int n) {
    ll result = ceil(log(n));
    return 1 << (result + 1);
}

void build(
    vector<ll>& arr,
    int node,
    int start,
    int end
) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        // 내부 노드: 자식들의 합계
        int mid = (start + end) / 2;

        // 왼쪽 자식 구축
        build(arr, 2*node, start, mid);
        // 오른쪽 자식 구축
        build(arr, 2*node+1, mid+1, end);

        // 현재 노드
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

// 목적: [l, r] 구간의 합 구하기
ll query(
    int node,
    int start,
    int end,
    int l,
    int r
) {
    // Case 1: 완전히 벗어남
    if (r < start || end < l) {
        return 0;
    }

    // Case 2: 완전히 포함됨
    if (l <= start && end <= r) {
        return tree[node];
    }

    // Case 3: 부분적으로 겹침 -> 분할해서 탐색
    int mid = (start + end) / 2;
    ll left_sum = query(2*node, start, mid, l, r);
    ll right_sum= query(2*node+1, mid+1, end, l, r);

    return left_sum + right_sum;
}

// 목적: idx 위치의 값을 val로 변경
void update(
    int node,
    int start,
    int end,
    int idx,
    ll val
) {
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

int main() {
    cin >> n;

    tree.resize(getTreeSize(n));

    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    build(arr, 1, 0, n-1);
}
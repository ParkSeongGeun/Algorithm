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

int main() {
    cin >> n;

    tree.resize(getTreeSize(n));

    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    build(arr, 1, 0, n-1);
}
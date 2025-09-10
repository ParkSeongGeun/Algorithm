// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// typedef long long ll;

// int n, m;
// vector<ll> tree;

// int getTreeSize(int n) {
//     int height = (int)ceil(log2(n));
//     return 1 << (height + 1);
// }

// void build(
//     vector<ll>& arr, 
//     int node, 
//     int start, 
//     int end) {
//     if (start == end) {
//         // 리프 노드: 배열의 실제 값
//         tree[node] = arr[start];
//     } else {
//         // 내부 노드: 자식들의 합계
//         int mid = (start + end) / 2;

//         // 왼쪽 자식 구축
//         build(arr, 2*node, start, mid);
//         // 오른쪽 자식 구축
//         build(arr, 2*node+1, mid+1, end);

//         // 현재 노드 = 왼쪽 + 오른쪽의 합
//         tree[node] = tree[node * 2] + tree[node * 2 + 1];
//     }
// }

// // [left, right] 구간의 합 구하기
// ll query(
//     int node,
//     int start,
//     int end,
//     int l,
//     int r
// ) {
//     // Case 1: 완전히 벗어남
//     //  -> 합에 영향 없음
//     if (r < start || end < l) {
//         return 0;
//     }

//     // Case 2: 완전히 포함됨
//     //  -> 현재 노드 값 반환
//     if (l <= start && end <= r) {
//         return tree[node]; 
//     }

//     // Case 3: 부분적으로 겹침 -> 분할해서 탐색
//     int mid = (start + end) / 2;
//     ll left_sum = query(2*node, start, mid, l, r);
//     ll right_sum = query(2*node+1, mid+1, end, l, r);

//     return left_sum + right_sum;
// }

// void update(
//     int node,
//     int start,
//     int end,
//     int idx,
//     ll val
// ) {
//     if (start == end) {
//         // 리프 노드 도달: 값 변경
//         tree[node] = val;
//     } else {
//         // 내부 노드: 해당 자식으로 이동
//         int mid = (start + end) / 2;

//         if (idx <= mid) {
//             update(2*node, start, mid, idx, val);
//         } else {
//             update(2*node+1, mid+1, end, idx, val);
//         }

//         // 자식들 변경 후 현재 노드 업데이트
//         tree[node] = tree[node * 2] + tree[node * 2 + 1];
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     cin >> n >> m;
    
//     tree.resize(getTreeSize(n));
    
//     vector<ll> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }

//     build(arr, 1, 0, n-1);

//     for(int i=0;i<m;i++) {
//         int l, r;

//         cin >> l >> r;
//         cout << query(1, 0, n-1, l - 1, r - 1) << "\n";
//     }

//     return 0;
// }

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<long long> prefix(n+1, 0);
    
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        prefix[i] = prefix[i-1] + x;
    }
    
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << "\n";
    }
    
    return 0;
}
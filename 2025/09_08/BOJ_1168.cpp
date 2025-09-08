#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a, b;
int seg[(1<<18)]; // 2^18 = 262,144 크기 배열 (최대 N=100,000이므로 충분)

// ============ 세그먼트 트리 초기화 ============
int init(int node, int s, int e) { // (현재 노드 번호, 구간 시작, 구간 끝)
    if (s==e) { // 리프 노드에 도달 (더 이상 나눌 수 없음)
        return seg[node] = 1; // 각 사람은 처음에 살아있으므로 1
    }
    int mid = (s+e)/2; // 구간을 반으로 나누기 위한 중점
    // 왼쪽 자식(2*node) + 오른쪽 자식(2*node+1)의 합을 현재 노드에 저장
    return seg[node] = init(2*node, s, mid) + init(2*node+1, mid+1, e);
}

// ============ 특정 사람 제거 (세그먼트 트리 업데이트) ============
int update(int node, int s, int e, int del) { // del: 제거할 사람의 실제 번호
    seg[node]--; // 현재 노드의 살아있는 사람 수 1 감소
    if (s==e) { // 리프 노드 도달 (제거할 사람 찾음)
        return 0; // 해당 사람은 이제 0 (죽음)
    } else {
        int mid = (s+e)/2;
        if (del <= mid) { // 제거할 사람이 왼쪽 구간에 있음
            return update(2*node, s, mid, del);
        } else { // 제거할 사람이 오른쪽 구간에 있음
            return update(2*node+1, mid+1, e, del);
        }
    }
}

// ============ order번째 살아있는 사람의 실제 번호 찾기 ============
int query(int node, int s, int e, int order) { // order: 몇 번째 살아있는 사람인지
    if (s==e) { // 리프 노드 도달
        return s; // 해당 구간의 시작점 = 찾는 사람의 실제 번호
    }
    int mid = (s+e)/2;

    if (order <= seg[2*node]) { // 왼쪽 자식의 살아있는 사람 수 >= order
        // order번째 사람이 왼쪽 구간에 있음
        return query(2*node, s, mid, order);
    } else { 
        // order번째 사람이 오른쪽 구간에 있음
        // 오른쪽에서는 (order - 왼쪽구간의살아있는사람수)번째를 찾아야 함
        return query(2*node+1, mid+1, e, order-seg[2*node]);
    }
}

int main() {
    cin >> n >> k;
    init(1, 1, n); // 노드1번부터, 1번~n번 사람으로 트리 초기화

    int idx = 1; // 현재 위치 (처음에는 1번째 살아있는 사람부터 시작)

    cout << "<";
    for(int i=0;i<n;i++){ // n명 모두 제거할 때까지
        int size = n-i; // 현재 살아있는 사람 수
        idx += k-1; // 현재 위치에서 k-1만큼 이동 (현재 사람 포함해서 k번째)

        // ============ 원형 큐 시뮬레이션 ============
        if (idx%size==0) { // idx가 size의 배수면 마지막 사람
            idx = size; // size번째 (마지막) 사람
        } else if (idx > size) { // idx가 범위를 넘어가면
            idx %= size; // 나머지 연산으로 순환
        }
        // 예: size=5, idx=7이면 idx=2가 됨 (7%5=2)

        // idx번째 살아있는 사람의 실제 번호 찾기
        int num = query(1, 1, n, idx);

        // 해당 사람을 세그먼트 트리에서 제거
        update(1, 1, n, num);

        // 출력 형식 맞추기
        if (i==n-1) {
            cout << num;
        } else {
            cout << num << ", ";
        }
    }
    cout << ">";

    return 0;
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits> // INT_MAX를 사용하기 위한 헤더

using namespace std;

int N, sum;
int MAP[11][11];
bool visited[11];

void go(int start) {
    queue< pair<int, int> > q;
    q.push(make_pair(start, 0));
    visited[start] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int cur = q.front().second;
        q.pop();

        // 이 부분은 방문한 도시와 현재 비용을 출력하는 부분입니다.
        cout << x << " " << cur << "\n";

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && MAP[x][i] != 0) {
                // 방문하지 않은 도시이며 갈 수 있는 도시인 경우
                visited[i] = true;
                q.push(make_pair(i, cur + MAP[x][i]));
                visited[i] = false; // BFS에서는 큐에 넣고 방문 체크를 해제하는 방식을 사용하므로 다시 방문 여부를 false로 설정해줍니다.
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int res = INT_MAX;
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
        }
    }

    // 각 도시에서 출발하는 경우를 모두 시도
    for (int i = 1; i <= N; i++) {
        fill(visited, visited + 11, false); // 방문 여부 초기화
        go(i);
    }

    return 0;
}

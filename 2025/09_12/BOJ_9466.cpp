#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int T, cnt;
int map[100001];
bool visited[100001];
bool done[100001];

void findCycle(int num) {
    visited[num] = true;
    int next = map[num];

    if (!visited[next]) {
        findCycle(next);
    } else if (!done[next]) {
        int current = next;
        do {
            cnt++;
            current = map[current];
        } while (current != next);
    }
    done[num] = true;
}

int main() {
    cin >> T;
    for(int i=0;i<T;i++){
        int a;
        cin >> a;
        for(int i=1;i<=a;i++) {
            cin >> map[i];
        }

        for(int i=1;i<=a;i++){
            if (!visited[i]) {
                findCycle(i);
            }
        }
        cout << a - cnt << "\n";
        cnt = 0;
        memset(visited, false, sizeof(visited));
        memset(done, false, sizeof(done));
        memset(map, 0, sizeof(map));
    }

    return 0;
}

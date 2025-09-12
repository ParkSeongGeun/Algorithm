#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int grid[25][25];
bool visited[25][25];
vector<int> houseCounts;

// 상하좌우 이동을 위한 방향 배열
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int N;

int dfs(int row, int col) {
    visited[row][col] = true;
    int houseCount = 1; // 현재 집 포함
    
    // 4방향 탐색
    for(int dir = 0; dir < 4; dir++) {
        int newRow = row + dr[dir];
        int newCol = col + dc[dir];
        
        // 범위 체크
        if(newRow < 0 || newRow >= N || newCol < 0 || newCol >= N) {
            continue;
        }
        
        // 방문하지 않았고 집이 있으면 탐색
        if(!visited[newRow][newCol] && grid[newRow][newCol] == 1) {
            houseCount += dfs(newRow, newCol);
        }
    }
    
    return houseCount;
}

int main() {
    cin >> N;
    
    // 입력 처리
    for(int i = 0; i < N; i++) {
        string line;
        cin >> line;
        
        for(int j = 0; j < line.length(); j++) {
            grid[i][j] = line[j] - '0'; // 문자를 숫자로 변환
            visited[i][j] = false;
        }
    }
    
    // 모든 위치에서 단지 탐색
    int complexCount = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                int houseCount = dfs(i, j);
                houseCounts.push_back(houseCount);
                complexCount++;
            }
        }
    }
    
    sort(houseCounts.begin(), houseCounts.end());
    
    cout << complexCount << "\n";
    for(int count : houseCounts) {
        cout << count << "\n";
    }
    
    return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 50;

int width, height;
int islandCount = 0;
int grid[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void dfs(int y, int x) {
    visited[y][x] = true;
    
    for (int dir = 0; dir < 8; dir++) {
        int newY = y + dy[dir];
        int newX = x + dx[dir];
        
        if (newX < 0 || newX >= width || newY < 0 || newY >= height) {
            continue;
        }
        
        if (grid[newY][newX] == 1 && !visited[newY][newX]) {
            dfs(newY, newX);
        }
    }
}

int main() {
    while (true) {
        cin >> width >> height;
        
        if (width == 0 && height == 0) {
            break;
        }
        
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                cin >> grid[y][x];
            }
        }
        
        // 모든 위치에서 섬 탐색
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (grid[y][x] == 1 && !visited[y][x]) {
                    islandCount++;
                    dfs(y, x);
                }
            }
        }

        cout << islandCount << "\n";
        
        memset(grid, 0, sizeof(grid));
        memset(visited, false, sizeof(visited));
        islandCount = 0;
    }
    
    return 0;
}
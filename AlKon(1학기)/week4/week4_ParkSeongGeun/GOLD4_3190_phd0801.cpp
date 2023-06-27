#include <bits/stdc++.h>	

using namespace std;

int N;
int MAP[101][101];
int visited[101][101];
queue<pair<int, char>> q; // 방향 전환 시간, 방향
int dir;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j] = 1; // 맵 생성
		}
	}
	int a; // 사과 입력 개수
	cin >> a;
	for (int i = 0; i < a; i++) {
		int row, col;
		cin >> row >> col;
		MAP[row][col] = 2; // 사과는 2로 표시
	}
	int b; // 방향 전환 횟수
	cin >> b;
	for (int i = 0; i < b; i++) {
		int t;
		char dir;
		cin >> t >> dir;
		q.push({ t,dir }); // 방향 전환 시간, 방향 queue에 입력
	}
	queue<pair<int, int>> snake; //뱀의 좌표 담는 queue
	int count = 0;
	int left_count = 0;
	int right_count = 0;
	int move_x[4] = { 1,0,-1,0 }; // 방향 설정 
	int move_y[4] = { 0,1,0,-1 };
	int x = 1;
	int y = 1;
	snake.push({ x,y });
	visited[1][1] = 1;
	while (1) { // 뱀 출발
		if (!q.empty()&&q.front().first == count) {
			if (q.front().second == 'D') {
				dir = (dir + 1) % 4;
				x += move_y[dir];
				y += move_x[dir];
				snake.push({ x,y });
			}
			else {
				dir = (dir + 3) % 4;
				x += move_y[dir];
				y += move_x[dir];
				snake.push({ x,y });
			}
			q.pop();
		}
		else {
			x += move_y[dir];
			y += move_x[dir];
			snake.push({ x,y });
		}
		if (MAP[snake.back().first][snake.back().second] == 2) {
			MAP[snake.back().first][snake.back().second] = 1;
			a--;
			if (visited[snake.back().first][snake.back().second] == 1) {
				count++;
				cout << "겹침" << "\n";
				break;
			}
			else {
				visited[snake.back().first][snake.back().second] = 1;
			}
		}
		else {
			if (count != 0) {
				if (visited[snake.back().first][snake.back().second] == 1) {
					count++;
					cout << "겹침" << "\n";
					break;
				}
				else {
					visited[snake.back().first][snake.back().second] = 1;
				}
				visited[snake.front().first][snake.front().second] = 0;
				snake.pop();
			}
		}
		count++;
		if (MAP[snake.back().first][snake.back().second] == 0) {
			cout << "벽에 부딪힘" << "\n";
			break;
		}
	}
	cout << count;
	return 0;
}
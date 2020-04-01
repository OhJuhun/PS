#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[14][8];
bool visit[14][8];
int ans = 0;
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };

struct item {
	int x, y, len;
};
void down() {
	for (int j = 1; j <= 6; j++) {
		int floor = 12;
		for (int i = 12; i > 0; i--) {
			if (arr[i][j] != 0) {
				//뿌요라면
				int tmp = arr[i][j];
				arr[i][j] = 0;
				arr[floor][j] = tmp;
				floor--;
			}
		}
	}
}
void setInit() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			visit[i][j] = false;
		}
	}
}
void boom() {
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			if (visit[i][j])
				arr[i][j] = 0;
			visit[i][j] = false;
		}
	}
}
int bfs(int x,int y,int t) {
	item it = { x,y,1 };
	queue<item> q;
	q.push(it);
	int tmp = 1;
	visit[x][y] = true;
	while (!q.empty()) {
		item c = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			item n = { c.x + dir[i][0],c.y + dir[i][1],c.len + 1 };
			if (arr[n.x][n.y] == t && !visit[n.x][n.y]) {
				q.push(n);
				tmp++;
				visit[n.x][n.y] = true;
			}
		}
	}
	return tmp;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			char a;
			cin >> a;
			if (a == '.') {
				arr[i][j] = 0;
			}
			if (a == 'R')
				arr[i][j] = 1;
			if (a == 'G')
				arr[i][j] = 2;
			if (a == 'B')
				arr[i][j] = 3;
			if (a == 'P')
				arr[i][j] = 4;
			if (a == 'Y')
				arr[i][j] = 5;
		}
	}
	down();
	int answer = 0;
	bool flag = false;;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
		//	cout << arr[i][j];
			if (arr[i][j] > 0)
				flag = true;
		}
	//	cout << endl;
	}
	//맨아래부터 bfs하면서 터트린다
	while (true) {
		bool flag = false;;
		for (int i = 1; i <= 12; i++) {
			for (int j = 1; j <= 6; j++) {
				if (arr[i][j] > 0)
					flag = true;
			}
		}
		if (!flag) break;
		bool _flag = false;
		for (int i = 12; i > 0; i--) {
			for (int j = 1; j <= 6; j++) {
				if (arr[i][j] > 0) {
					int ans = bfs(i, j,arr[i][j]);
					
					if (ans >= 4) {
						_flag = true;
						//폭발이 가능한 겨웅
						boom();
						//answer++;
					}
					else
						setInit(); //폭발 불가능한 경우
				} //일단 고른뒤에 비짓인 곳을 다 지운다
			}
		}
		down();
		if (!_flag) break;
		answer++;
	}
	cout << answer << endl;
	return 0;
}
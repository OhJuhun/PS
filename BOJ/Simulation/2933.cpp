#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int R, C, N;
char arr[101][101];
int stick[100];
int visit[101][101]; //i번width
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
void clustering(int r, int c,int t) {
	//바닥에서 출발하여 클러스터링 가능한 것만 모은다
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	visit[r][c] = t;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next;
			next.first = cur.first + dir[i][0];
			next.second = cur.second + dir[i][1];
			if (next.first > R || next.second > C || next.first < 1 || next.second < 1 || visit[next.first][next.second] || arr[next.first][next.second] == '.') continue;
			q.push(next);
			visit[next.first][next.second] = t;
		}
	}
}

void downing(int c) {
	int cnt = 0;
	for (int i = R; i >= 1; i--) {

		if (arr[i][c] == '.') {
			cnt++;
		}
		else {
			arr[i][c] = '.';
			arr[i +1][c] = 'x';
		}
	}
}
void throwstick(int n) {
	int start = 0;
	int i = R - stick[n] + 1;
	if (n % 2 == 0) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] == 'x') {
				arr[i][j] = '.';
				break;
			}
		}
	}
	else {
		for (int j = C; j >= 1; j--) {
			if (arr[i][j] == 'x') {
				arr[i][j] = '.';
				break;
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	for (int j = 1; j <= C; j++)
		if(arr[R][j]=='x') clustering(R,j,1);
	//바닥과 닿아있는 클러스터를 찾음
	bool flag = false;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] == 'x' && visit[i][j] == 0) {
				clustering(i, j, 2);
				flag = true;
			}
		}
	} //공중에 떠있는 클러스터를 2로
	if (flag) {
		bool stop = true;
		while (stop) {
			for (int i = R-1; i >0; i--) {
				for (int j = 1; j <= C; j++) {
					if (visit[i][j] == 2) {
						visit[i + 1][j] = 2;
						visit[i][j] = 0;
						if (i + 1 == R || visit[i + 2][j] == 1) stop = false;
					}
				}
			}
		}
		memset(arr, '.', sizeof(arr));
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++)
				if (visit[i][j]) arr[i][j] = 'x';
		}
	}
}
void solve() {
	for (int i = 0; i < N; i++) {
		throwstick(i);
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			cout << arr[i][j];
		cout << '\n';
	}
}
void input() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++)
			cin >> arr[i][j];
	}
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> stick[i];
}
int main() {
	PREPROCESS;
	input();
	solve();
	return 0;
}
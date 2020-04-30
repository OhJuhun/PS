#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int R, C, T;
int arr[51][51];
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
pair<int, int> head;
pair<int, int> tail;
void spead(int r, int c,int s) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int dr = r + dir[i][0];
		int dc = c + dir[i][1];
		if (dr<1 || dc<1 || dr>R || dc>C || arr[dr][dc] == -1) continue; //확산X
		arr[dr][dc] += s/ 5;
		cnt++;
	}
	arr[r][c] -= ((s / 5)*cnt);
}

void airfresher() {
	int r = head.first;
	int c = head.second;
	//위에 있는 애들 먼저 제거
	while (r > 1) {
		if (arr[r][c] == -1) {
			arr[r - 1][c] = 0;
		}
		else {
			arr[r][c] = arr[r-1][c];
		}
		r--;
	}
	while (c < C) {
		arr[r][c] = arr[r][c + 1];
		c++;
	}
	while (r < head.first) {
		arr[r][c] = arr[r + 1][c];
		r++;
	}
	while (c > 2) {
		arr[r][c] = arr[r][c - 1];
		c--;
	}
	arr[head.first][2] = 0;

	r = tail.first;
	c = tail.second;
	while (r < R) {
		if (arr[r][c] != -1) arr[r][c] = arr[r + 1][c];
		r++;
	}
	while (c < C) {
		arr[r][c] = arr[r][c + 1];
		c++;
	}
	while (r > tail.first) {
		arr[r][c] = arr[r - 1][c];
		r--;
	}
	while (c > 2) {
		arr[r][c] = arr[r][c-1];
		c--;
	}
	arr[tail.first][2] = 0;

}
int solve() {
	int ret = 0;

	while (T--) {
		queue<pair<int, int>> origin;
		queue<int> q;
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (arr[i][j] > 0) origin.push(make_pair(i, j)), q.push(arr[i][j]);
			}
		}
		while (!origin.empty()) {
			spead(origin.front().first, origin.front().second,q.front());
			origin.pop();
			q.pop();
		} //spead monge
	
		airfresher();
	}
	for (int i = 1; i<= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j] == -1) continue;
			ret += arr[i][j];
		}
	}
	return ret;
}
void input() {
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) {
				if (head.first == 0)
					head = make_pair(i, j);
				else
					tail = make_pair(i, j);
			}
		}
	}
}
int main() {
	PREPROCESS;
	input();
	cout << solve() << endl;
	return 0;
}
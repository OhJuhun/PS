#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int N, M;
int arr[9][9];
int tmparr[9][9];
int dir[5][8]; //4개의 cctv 종류와 8개의 위치
vector<pair<int, int>> cctvs[6];
int answer = 101;

bool canWatch(int dr, int dc) {
	if (arr[dr][dc] == 0) arr[dr][dc] = 9;
	return arr[dr][dc] != 6;
}
void left(int r, int c) {
	int dr = r;
	int dc = c;
	while (dc > 1) {
		dc--;
		if (!canWatch(dr, dc)) break;
	}
}
void right(int r, int c) {
	int dr = r;
	int dc = c;
	while (dc < M) {
		dc++;
		if (!canWatch(dr, dc)) break;
	}

}
void up(int r, int c) {
	int dr = r;
	int dc = c;
	while (dr > 1) {
		dr--;
		if (!canWatch(dr, dc)) break;
	}
}

void down(int r, int c) {
	int dr = r;
	int dc = c;
	while (dr < N) {
		dr++;
		if (!canWatch(dr, dc)) break;
	}

}

void cpy() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			arr[i][j] = tmparr[i][j];
	}
}

void watch(int i, int j) {
	int d = dir[i][j]; //i,j cctv의 방향
	int r = cctvs[i][j].first;
	int c = cctvs[i][j].second;
	if (i == 1) {
		//1번 CCTV
		//상 우 하 좌
		switch (d) {
		case 0:
			up(r,c);
			break;
		case 1:
			right(r, c);
			break;
		case 2:
			down(r, c);
			break;
		case 3:
			left(r, c);
			break;
		}
	}
	else if (i == 2) {
		//2번 cctv
		switch (d) {
		case 0:
			up(r, c);
			down(r, c);
			break;
		case 1:
			right(r, c);
			left(r, c);
			break;
		}
	}
	else if (i == 3) {
		switch (d) {
		case 0:
			up(r, c);
			right(r, c);
			break;
		case 1:
			right(r, c);
			down(r, c);
			break;
		case 2:
			down(r, c);
			left(r, c);
			break;
		case 3:
			left(r, c);
			up(r, c);
			break;
		}
	}
	else {
		switch (d) {
		case 0:
			left(r, c);
			up(r, c);
			right(r, c);
			break;
		case 1:
			up(r, c);
			right(r, c);
			down(r, c);
			break;
		case 2:
			right(r, c);
			down(r, c);
			left(r, c);
			break;
		case 3:
			down(r, c);
			left(r, c);
			up(r, c);
			break;
		}
	}
}
void dfs(int n, int t) {
	if (n == 5) {
		cpy();
		for (int i = 1; i < 5; i++) {
			for (int j = 0; j < cctvs[i].size(); j++) {
				watch(i, j);
			}
		}
		
		int tmp = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (arr[i][j] == 0) tmp++;
			}
		}

		answer = min(tmp, answer);
		return;
	}
	if (t == cctvs[n].size()) {
		dfs(n + 1, 0);
		return;
	}
	if (n != 2) {
		for (int i = 0; i < 4; i++) {
			dir[n][t] = i;
			dfs(n, t + 1);
		}
	}
	else
		for (int i = 0; i < 2; i++) {
			dir[n][t] = i;
			dfs(n, t + 1);
		}
}
void solve() {
	for (int i = 0; i < cctvs[5].size(); i++) {
		int r = cctvs[5][i].first;
		int c = cctvs[5][i].second;
		up(r, c);
		down(r, c);
		right(r, c);
		left(r, c);

	}
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			tmparr[i][j] = arr[i][j];

	dfs(1, 0);
}
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] && arr[i][j] != 6) {
				cctvs[arr[i][j]].push_back(make_pair(i, j));
			}
		}
	}
}
int main() {
	PREPROCESS;
	input();
	solve();
	cout << answer << endl;
	return 0;
}
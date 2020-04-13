#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

struct wormhole {
	int r[2], c[2];
};

int N, T;
int arr[101][101];
wormhole h[11];
pair<int, int> blackhole;
pair<int, int> start;
int ans;
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int changeDir(int d, int num) {
	//도착할 곳의 r,c
	if (d == 0) { //아래로갈 떄
		if (num == 2 || num == 3 || num == 5) return 1; 
		else if (num == 1) return 2;
		
		else if (num == 4) return 3;
	}
	else if (d == 1) {//위로갈 때
		if (num == 1 || num == 4 || num == 5) return 0;
		else if (num == 2) return 2;
		else if (num == 3) return 3;
	}
	else if (d == 2) {//오른쪽으로갈 때
		if (num == 1 || num == 2 || num == 5) return 3;
		else if (num == 3) return 0;
		else if (num == 4) return 1;

	}
	else if (d == 3) { //왼쪽으로 갈 때
		if (num == 3 || num == 4 || num == 5) return 2;
		else if (num == 1) return 1;
		else if (num == 2) return 0;

	}
}
void go(int r,int c,int d) {
	bool first = true;
	int score = 0;
	while (true) {
		int dr = r + dir[d][0];
		int dc = c + dir[d][1];

		if (!first && ((r == start.first && c == start.second) || (arr[dr][dc] == -1))) {
			ans = max(ans, score);
			return;
		}
		first = false;
		if (dr<1 || dc<1 || dr>N || dc>N) {
			//범위를 벗어난 경우
			d=changeDir(d, 5);
			score++;
			r = dr;
			c = dc;
		}
		else if (arr[dr][dc]==0) {
			//범위내인경우
			r = dr;
			c = dc;
		}
		else if (arr[dr][dc] > 0 && arr[dr][dc] < 6) {
			//상자인경우
			d=changeDir(d, arr[dr][dc]);
			r = dr;
			c = dc;
			score++;
		}
		else if (arr[dr][dc] > 5 && arr[dr][dc] < 11) {
			//웜홀인 경우 위치만 변경
			int idx = arr[dr][dc];
			if (h[idx].r[0] == dr && h[idx].c[0] == dc) {
				r = h[idx].r[1];
				c = h[idx].c[1];
			}
			else {
				r = h[idx].r[0];
				c = h[idx].c[0];
			}
		}
	}
}
void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 0) {
				start.first = i;
				start.second = j;
				for (int k = 0; k < 4; k++) {
					go(i,j,k); //시작 방향
				}
			}
		}
	}
}
void initialize() {
	memset(arr, 0, sizeof(arr));
	for (int i = 6; i <= 10; i++) {
		h[i].r[0] = 0;
		h[i].r[1] = 0;
		h[i].c[0] = 0;
		h[i].c[1] = 0;
	}
	blackhole.first = 0;
	blackhole.second = 0;
	ans = 0;
	start.first = 1;
	start.second = 1;
}

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 5) {
				//웜홀일 때
				int num = arr[i][j];
				if (h[num].r[0] == 0) {
					h[num].r[0] = i;
					h[num].c[0] = j;
				}
				else {
					h[num].r[1] = i;
					h[num].c[1] = j;
				}
			}
			else if (arr[i][j] == -1) {
				blackhole.first = i;
				blackhole.second = j;
			}
		}
	}
}
int main() {
	PREPROCESS;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		initialize();
		input();
		solve();
		cout << "#" << i << " " << ans << '\n';
	}
	return 0;
}
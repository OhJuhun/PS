#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int N;
int arr[21][21];
int tmparr[21][21];
int v[5]; //0상 1하 2좌 3 우
int ans;

void up() {
	for (int j = 1; j <= N; j++) {
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			if (tmparr[i][j] == 0) {
				cnt++;
			}
			else if(cnt!=0){
				tmparr[i - cnt][j] = tmparr[i][j];
				tmparr[i][j] = 0;
				
				i = i - cnt;
				cnt = 0;
			}
		}
		for (int i = 1; i < N; i++) {
			if (tmparr[i][j] == tmparr[i + 1][j] && tmparr[i][j] != 0) {
				tmparr[i][j] *= 2;
				for (int ii = i + 1; ii <= N; ii++) {
					tmparr[ii][j] = tmparr[ii + 1][j];
				}
			}
		}
	}
}

void left() {
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (tmparr[i][j] == 0) cnt++;
			else if (cnt != 0) {
				tmparr[i][j - cnt] = tmparr[i][j];
				tmparr[i][j] = 0;
				j = j - cnt;
				cnt = 0;
			}
		}
		for (int j = 1; j < N; j++) {
			if (tmparr[i][j] == tmparr[i][j+1] && tmparr[i][j] != 0) {
				tmparr[i][j] *= 2;
				for (int jj = j + 1; jj <= N; jj++) {
					tmparr[i][jj] = tmparr[i][jj + 1];
				}
			}
		}
	}
}

void down() {
	for (int j = 1; j <= N; j++) {
		int cnt = 0;
		for (int i = N; i > 0; i--) {
			if (tmparr[i][j] == 0) cnt++;
			else if (cnt != 0) {
				tmparr[i + cnt][j] = tmparr[i][j];
				tmparr[i][j] = 0;
				i = i + cnt;
				cnt = 0;
			}
		}
		for (int i = N; i > 1; i--) {
			if (tmparr[i][j] == tmparr[i - 1][j] && tmparr[i][j] != 0) {
				tmparr[i][j] *= 2;
				for (int ii = i - 1; ii > 0; ii--) {
					tmparr[ii][j] = tmparr[ii - 1][j];
				}
			}
		}
	}
}

void right() {
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = N; j > 0; j--) {
			if (tmparr[i][j] == 0) cnt++;
			else if (cnt != 0) {
				tmparr[i][j + cnt] = tmparr[i][j];
				tmparr[i][j] = 0;
				j = j + cnt;
				cnt = 0;
			}
		}
		for (int j = N; j > 1; j--) {
			if (tmparr[i][j] == tmparr[i][j - 1] && tmparr[i][j] != 0) {
				tmparr[i][j] *= 2;
				for (int jj = j - 1; jj > 0; jj--) {
					tmparr[i][jj] = tmparr[i][jj - 1];
				}
			}
		}
	}
}
void move() {
	for (int i = 0; i < 5; i++) {
		if (v[i] == 0) {
			up();
		}
		else if (v[i] == 1) {
			down();
		}
		else if (v[i] == 2) {
			left();
		}
		else if (v[i] == 3) {
			right();
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			ans = max(ans, tmparr[i][j]);
	}
}
void cpy() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			tmparr[i][j] = arr[i][j];
	}
}
void dfs(int t) {
	if (t >=5){
		cpy();
		move();
		return;
	}
	for (int i = 0; i < 4; i++) {
		v[t] = i;
		dfs(t + 1);
	}
}
void solve() {
	dfs(0);
}
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
}
int main() {
	PREPROCESS;
	input();
	
	solve();
	cout << ans << '\n';
	return 0;
}
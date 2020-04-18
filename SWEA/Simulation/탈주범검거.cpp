#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 98765432

//탈주범이 잇을 수 있는 위치

struct pipe {
	int r, c, s,t;
};
int N, M, R, C, L;
set<pair<int, int>> ans;
int arr[51][51];
bool visit[51][51];

int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
void solve() {
	queue<pipe> q;
	pipe f;
	f.r = R;
	f.c = C;
	f.s = arr[R][C];
	f.t = 1;
	visit[R][C] = true;
	q.push(f);
	while (!q.empty()) {
		pipe cur = q.front();
		q.pop();
		ans.insert(make_pair(cur.r, cur.c));
		if (cur.s == 1) {
			for (int i = 0; i < 4; i++) {
				pipe next = cur;
				next.r += dir[i][0];
				next.c += dir[i][1];
				next.t++;
				if (next.t > L || next.r < 0 || next.c < 0 || next.r >= N || next.c >= M || visit[next.r][next.c] || arr[next.r][next.c] == 0) {
					continue;
				}
				if (i == 0) { //위로 1256
					if (arr[next.r][next.c] == 3 || arr[next.r][next.c] == 4 || arr[next.r][next.c] == 7) continue;
				}
				else if (i == 1) {//아래로
					if (arr[next.r][next.c] == 3 || arr[next.r][next.c] == 5 || arr[next.r][next.c] == 6) continue;

				}
				else if (i == 2) {// 좌우인거
					if (arr[next.r][next.c] == 2 || arr[next.r][next.c] == 4 || arr[next.r][next.c] == 5) continue;
				}
				else if (i == 3) {
					if (arr[next.r][next.c] == 2 || arr[next.r][next.c] == 6 || arr[next.r][next.c] == 7) continue;
				}
				next.s = arr[next.r][next.c];
				q.push(next);
				ans.insert(make_pair(next.r, next.c));
				visit[next.r][next.c] = true;
			}
		}
		else if (cur.s == 2) {
			pipe next = cur;
			next.r++;
			next.t++;
			if (next.t <= L && next.r>=0 && next.c>=0 && next.r<N && next.c<M && !visit[next.r][next.c] && arr[next.r][next.c]!=0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 2 || arr[next.r][next.c] == 4 || arr[next.r][next.c] == 7) { //1247
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
			next = cur;
			next.r--;
			next.t++;
			if (next.t <= L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 2 || arr[next.r][next.c] == 5 || arr[next.r][next.c] == 6) {//1256
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
		}
		else if (cur.s == 3) {
			pipe next = cur;
			next.c++;
			next.t++;
			if (next.t <= L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 3 || arr[next.r][next.c] == 6  || arr[next.r][next.c]==7) {
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
			next = cur;
			next.c--;
			next.t++;
			if (next.t <= L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 3 || arr[next.r][next.c] == 4 || arr[next.r][next.c] == 5) {
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
		}
		else if (cur.s == 4) {
			pipe next = cur;
			next.r--;
			next.t++;
			if (next.t <=L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 2 || arr[next.r][next.c] == 5 || arr[next.r][next.c] == 6) {//1256
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
			next = cur;
			next.c++;
			next.t++;
			if (next.t <= L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 3 || arr[next.r][next.c] == 6 || arr[next.r][next.c] == 7) {
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
		}
		else if (cur.s == 5) {
			pipe next = cur;
			next.r++;
			next.t++;
			if (next.t <= L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 2 || arr[next.r][next.c] == 4 || arr[next.r][next.c] == 7) {
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
			next = cur;
			next.c++;
			next.t++;
			if (next.t <= L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 3 || arr[next.r][next.c] == 6 || arr[next.r][next.c] == 7) {
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
		}
		else if (cur.s == 6) {
			pipe next = cur;
			next.r++;
			next.t++;
			if (next.t <= L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 2 || arr[next.r][next.c] == 4 || arr[next.r][next.c] == 7) {
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
			next = cur;
			next.c--;
			next.t++;
			if (next.t <= L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 3 || arr[next.r][next.c] == 4 || arr[next.r][next.c] == 5) {
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
		}
		else if (cur.s == 7) {
			pipe next = cur;
			next.r--;
			next.t++;
			if (next.t <= L && next.r>=0 && next.c>=0 && next.r<N && next.c<M && !visit[next.r][next.c] && arr[next.r][next.c]!=0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 2 || arr[next.r][next.c] == 5 || arr[next.r][next.c] == 6) {//1256
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));

					visit[next.r][next.c] = true;
				}
			}
			next = cur;
			next.c--;
			next.t++;
			if (next.t <= L && next.r >= 0 && next.c >= 0 && next.r < N && next.c < M && !visit[next.r][next.c] && arr[next.r][next.c] != 0) {
				if (arr[next.r][next.c] == 1 || arr[next.r][next.c] == 3 || arr[next.r][next.c] == 4 || arr[next.r][next.c] == 5) {
					next.s = arr[next.r][next.c];
					q.push(next);
					ans.insert(make_pair(next.r, next.c));
					visit[next.r][next.c] = true;
				}
			}
		}

	}
}
void input() {
	cin >> N >> M >> R >> C >> L;
	ans.clear();
	memset(arr, 0, sizeof(arr));
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
}
int main() {
	PREPROCESS;
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		input();
		solve();
		cout << "#" << i << " " << ans.size() << '\n';
	}
	return 0;
}
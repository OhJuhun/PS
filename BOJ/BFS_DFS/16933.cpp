#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define MAX 987654321
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)

struct item {
	int r, c, l, k, d;
};
int N, M, K;
char arr[1001][1001];
bool visit[1001][1001][11];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
}

int bfs() {
	queue<item> q;
	q.push({ 1,1,1,K,1 });
	visit[1][1][K] = true;
	while (!q.empty()) {
		item cur = q.front();
		q.pop();
		//	bool reinsert = false;
		for (int i = 0; i < 4; i++) {
			item next = { cur.r + dir[i][0],cur.c + dir[i][1],cur.l + 1,cur.k,cur.d ^ 1 };
			if (next.r > 0 && next.c > 0 && next.r <= N && next.c <= M) {
				//범위 안에 존재하는 경우에만 
				if (arr[next.r][next.c] == '1') {
					//다음에 방문할 곳이 벽인 경우
					if (!cur.k) continue; //벽을 부술 수 없는 경우
					if (cur.d) {
						//현재가 낮이면 push
						if (visit[next.r][next.c][next.k - 1]) continue;
						//방문을 했었는지 확인
						next.k--;
						visit[next.r][next.c][next.k] = true;
						q.push(next);
					}
					else {
						//밤이면 움직일 수 없음
						q.push({ cur.r,cur.c,cur.l + 1,cur.k,cur.d ^ 1 });
						
					}
				}
				else {
					//벽이 아닌 경우
					if (next.r == N && next.c == M) {
						return next.l;
					}
					if (visit[next.r][next.c][next.k]) continue;
					//방문을 했었는지 확인한다
				//방문을 안했다면 push
					visit[next.r][next.c][next.k]= true;
					q.push(next);
				}
			}
		}
	}
	return -1;
}
int main() {
	PREPROCESS;
	input();
	if (N == 1 && M == 1) cout << 1 << endl;
	else cout << bfs() << '\n';
	return 0;
}
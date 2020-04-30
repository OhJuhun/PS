#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

struct ball {
	int r, c, d, l = 0;
};
struct ballinfo {
	int rr, rc, rl;
	int br, bc, bl;
	int cnt;
};
int N, M;
char arr[11][11];
int visit[11][11][11][11]; //rr,rc,br,bc
ball red;
ball blue;
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int answer = 11;

void solve() {
	queue<ballinfo> q;
	ballinfo bi;
	bi.rr = red.r;
	bi.rc = red.c;
	bi.br = blue.r;
	bi.bc = blue.c;
	bi.rl = 0;
	bi.bl = 0;
	bi.cnt = 0;
	q.push(bi);
	visit[red.r][red.c][blue.r][blue.c]++;
	while (!q.empty()) {
		ballinfo cur = q.front();
		if (cur.cnt > 10) continue;
		q.pop();
		for (int i = 0; i < 4; i++) {
			ballinfo next = cur;
			next.cnt++;
			if (next.cnt > 10) return;
			bool redIn = false;
			bool blueIn = false;

			while (true) {
				bool rf = false;
				bool bf = false;
				if (!redIn &&next.rr + dir[i][0] > 0 && next.rc + dir[i][1] > 0 && next.rr + dir[i][0] <= N && next.rc + dir[i][1] <= M && arr[next.rr + dir[i][0]][next.rc + dir[i][1]] != '#') {
					//갈 수 있는 곳일 경우 이동
					next.rr += dir[i][0];
					next.rc += dir[i][1];
					next.rl++;
					visit[next.rr][next.rc][next.br][next.bc]++;
					rf = true;
					if (arr[next.rr][next.rc] == 'O') {
						//구멍에 도달했다면
						redIn = true;
						rf = false;
					}
				}
				if (!blueIn && next.br + dir[i][0] > 0 && next.bc + dir[i][1] > 0 && next.br + dir[i][0] <= N && next.bc + dir[i][1] <= M && arr[next.br + dir[i][0]][next.bc + dir[i][1]] != '#') {
					next.br += dir[i][0];
					next.bc += dir[i][1];
					next.bl++;
					visit[next.rr][next.rc][next.br][next.bc]++;
					bf = true;
					if (arr[next.br][next.bc] == 'O') {
						blueIn = true;
						bf = false;
						break;
					}
				}
				if (!rf && !bf) break;
			}
			if (redIn && !blueIn) {
				answer = next.cnt;
				return;
			}
			else if (redIn && blueIn) {
				continue;
			}
			else if (!redIn && blueIn) continue;
			else {
				//위치 조정해주기
				if (visit[next.rr][next.rc][next.br][next.bc]>1) continue;
				if (next.br == next.rr && next.bc == next.rc) {
					visit[next.rr][next.rc][next.br][next.bc]--;
					if (next.bl > next.rl) {
						next.br -= dir[i][0];
						next.bc -= dir[i][1];
					}
					else {
						next.rr -= dir[i][0];
						next.rc -= dir[i][1];
					}
				}
				next.bl = 0;
				next.rl = 0;
				q.push(next);
			}
		}
	}
}
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'B') 
				blue.r = i, blue.c = j, blue.d = 0,arr[i][j]='.';
			if (arr[i][j] == 'R') 
				red.r = i, red.c = j, red.d = 0,arr[i][j]='.';
		}
	}
}
int main() {
//	PREPROCESS;
	input();
	solve();
	cout << (answer > 10 ? 0 : 1) << endl;
	return 0;
}
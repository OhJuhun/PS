#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

struct item {
	int r, c, remain;
};
int N, W, H;
int arr[16][13];
int sel[13];
int ans = 0;
int answer;
int arr2[16][13];
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

void cpy() {
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++)
			arr2[i][j] = arr[i][j];
	}
}
void bfs(int r, int c) {
	queue<item> q;
	item it;
	it.r = r;
	it.c = c;
	it.remain = arr2[r][c];
	arr2[r][c] = 0;
	q.push(it);
	while (!q.empty()) {
		item cur = q.front();
		q.pop();
		if (cur.remain < 1) continue;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < cur.remain; j++) {
				item next;
				next.r = cur.r + dir[i][0] * j; //0일때 현위치
				next.c = cur.c + dir[i][1] * j;
				if (next.r > H || next.c > W || next.r < 1 || next.c < 1 || arr2[next.r][next.c] == 0) continue;
				next.remain = arr2[next.r][next.c];
				arr2[next.r][next.c] = 0;
				q.push(next);
			}
		}
	}
}
void boom() {
	for (int i = 1; i <= N; i++) {
		int idx = 0;
		for (int j = 1; j <= H; j++) {
			if (arr2[j][sel[i]] != 0) {
				idx = j;
				break;
			}
		}
		
		bfs(idx, sel[i]);
		//다운

		
		int space_num;
		for (int nc = 1; nc <= W; nc++) {
			space_num = 0;
			for (int nr = H ; nr > 0; nr--) {
				if (arr2[nr][nc] == 0) space_num++;
				else if (space_num != 0) {
					arr2[nr + space_num][nc] = arr2[nr][nc];
					arr2[nr][nc] = 0;
				}

			}

		}
		
	}
	int tmp = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (arr2[i][j] != 0) tmp++;
		}
	}

	ans = min(ans, tmp);
}
void dfs(int t) {
	if (t > N) {
		cpy();
		boom();
		return;
	}
	for (int i = 1; i <= W; i++)
		sel[t] = i, dfs(t + 1);
}
void solve() {
	dfs(1);
}
void input() {
	cin >> N >> W >> H;
	memset(arr, 0, sizeof(arr));
	ans = MAX;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++)
			cin >> arr[i][j];
	}
}

int main() {
	PREPROCESS;
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		input();
		solve();
		cout << "#" << i << " " << ans << '\n';
	}
	return 0;
}
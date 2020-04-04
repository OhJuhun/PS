#include <iostream>

#include <algorithm>
#include <queue>

using namespace std;

struct item {
	int dx, dy, len;
};
char island[51][51];
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };
int r, c;
int ans = 0;
bool visit[51][51];
void initvisit() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			visit[i][j] = false;
	}
}
void bfs(int dx, int dy) {
	queue<item> q;
	q.push({ dx,dy,0 });
	visit[dx][dy] = true;
	while (!q.empty()) {
		item cur = q.front();
		if (ans < cur.len)
			ans = cur.len;
		q.pop();
		for (int i = 0; i < 4; i++) {
			item n = { cur.dx + dir[i][0],cur.dy + dir[i][1],cur.len + 1 };
			if (n.dx >= 0 && n.dy >= 0 && n.dx < r && n.dy < c && island[n.dx][n.dy] == 'L' &&
				!visit[n.dx][n.dy]) {
				q.push(n);
				visit[n.dx][n.dy] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cin >> island[i][j];
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (island[i][j] == 'L') {
				bfs(i, j);
				initvisit();
			}
		}
	}
	cout << ans << endl;
	return 0;
}
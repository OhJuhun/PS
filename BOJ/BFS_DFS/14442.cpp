#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct item {
	int r, c, l,k;
};

int N, M, K;
char c[1001][1001];
bool visit[1001][1001][11];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin>>c[i][j];
		}
	}
	
	queue<item> q;
	int ans = -1
	q.push({ 1,1,1,K });
	while (!q.empty()) {
		item cur = q.front();
		if (cur.r == N && cur.c == M) {
			ans =cur.l;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			item next = { cur.r + dir[i][0],cur.c + dir[i][1],cur.l + 1 ,cur.k };
			if (next.r > N || next.c > M || next.r < 1 || next.c < 1 ||
				visit[next.r][next.c][next.k]) continue;
			//범위를 벗어난 경우
			if (c[next.r][next.c] == '0') {
				//	갈 수 있는 길인 경우
				visit[next.r][next.c][next.k] = true;
				q.push(next);
			}
			else if (c[next.r][next.c] == '1' && next.k > 0) {
				next.k--;
				visit[next.r][next.c][next.k] = true;
				q.push(next);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
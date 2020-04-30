#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int N;
int arr[101][101];
bool visit[101][101];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
void divide(int r, int c, int num) {
	queue<pair<int, int >> q;
	q.push(make_pair(r, c));
	
	visit[r][c] = true;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		arr[cur.first][cur.second] = num;
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = make_pair(cur.first + dir[i][0], cur.second + dir[i][1]);
			if (next.first > N || next.second > N || next.first < 1 || next.second < 1 || visit[next.first][next.second] || arr[next.first][next.second] ==0) continue;
			visit[next.first][next.second] = true;
			q.push(make_pair(next.first, next.second));
		}
	}

}

int connect(int r, int c, int tr, int tc) {
	return abs(tr - r) + abs(tc - c)-1;
}
int solve() {
	int num = 1;
	int ret = 100000;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!arr[i][j] || visit[i][j]) continue;
			divide(i, j, num++);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 0) continue;
			for (int ii = 1; ii <= N; ii++) {
				for (int jj = 1; jj <= N; jj++) {
					if ( (i != ii || j != jj) && arr[i][j] != arr[ii][jj] && arr[ii][jj]!=0) {
						ret = min(ret,connect(i, j, ii, jj));
					}
				}
			}
		}
	}
	return ret;
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
	cout << solve() << endl;
	return 0;
}
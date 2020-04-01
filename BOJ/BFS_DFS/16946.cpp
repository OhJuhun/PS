#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 987654321
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
int N, M;
char arr[1001][1001];
pair<int,int> roads[1001][1001];
bool visit[1001][1001];
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int idx = 1;
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M;j++)
			cin >> arr[i][j];
	}
}

void setArray(queue<pair<int, int>> q, int val) {
	while (!q.empty()) {
		roads[q.front().first][q.front().second] = { val,idx };
		q.pop();
	}
	idx++;
}
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	int len = 0;
	visit[i][j] = true;
	queue < pair<int, int>> r;
	while (!q.empty()) {
		len++;
		pair<int, int> cur = q.front();
		r.push(cur);
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> next = { cur.first + dir[i][0],cur.second + dir[i][1] };
			if (next.first > N || next.second > M || next.first < 1 || next.second < 1 ||
				visit[next.first][next.second] || arr[next.first][next.second] == '1')
				continue;
			//방문이 불가능한 경우
			visit[next.first][next.second] = true;
			q.push(next);
		}
	}
	setArray(r,len);
}
void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == '0' && !visit[i][j])
				bfs(i,j);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (arr[i][j] == '1') {
				int val = 1;
				int tmparr[4];
				for (int k = 0; k < 4; k++) {
					pair<int, int> next = { i + dir[k][0],j + dir[k][1] };
					tmparr[k] = roads[next.first][next.second].second;
					if (next.first > N || next.second > M || next.first < 1 || next.second < 1) continue;
					
					bool flag = true;
					for (int z = 0; z < k; z++) {
						if (tmparr[z] == tmparr[k]) {
							flag = false;
						}
					}
					if (!flag) continue;
						val += roads[next.first][next.second].first;
				}
			//	for (int qq = 0; qq < 4; qq++)
			//		cout << tmparr[qq] << " ";
			//	cout << endl;
				cout << val%10;
			}
			else {
				cout << 0;
			}
		}
		cout << '\n';
	}
}
int main() {
	PREPROCESS;
	
	input();
	solve();
	return 0;
}
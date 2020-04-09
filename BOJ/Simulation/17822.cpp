#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int N, M, T;
int X[51], K[51];
bool D[51];
int P[51][51];
bool visit[51][51];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int answer() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			ans += P[i][j];
	}
	return ans;
}

void notSameProcess() {
	double mean = 0;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (P[i][j] == 0) continue;
			cnt++, mean += P[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (P[i][j] == 0) continue;
			if ((double)P[i][j] > mean/cnt) P[i][j]--;
			else if((double)P[i][j]<mean/cnt) P[i][j]++;
		}
	}
}
void delnum() {
	bool turn = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			//1,1~N,M까지 BFS
			if (P[i][j] == 0) continue; //이미 비어있는 위치인 경우
			queue<pair<int, int>> q;
			vector<pair<int, int>> v;
			memset(visit, false, sizeof(visit));
			q.push(make_pair(i, j));
			v.push_back(make_pair(i, j));
			visit[i][j] = true;
			while (!q.empty()) {
				int cr = q.front().first;
				int cc = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nr = cr + dir[k][0]; 
					int nc = cc + dir[k][1];
					if (nc == 0) nc = M;
					if (nc == M + 1) nc = 1;
					//원판 안에서는 좌우 모두 가능
					if (nr<1 || nr>N || visit[nr][nc] || P[nr][nc] != P[cr][cc]) continue;
					visit[nr][nc] = true;
					q.push(make_pair(nr, nc));
					v.push_back(make_pair(nr, nc));
				}
			}
			if (v.size() > 1) {
				turn = true;
				for (int k = 0; k < v.size(); k++) {
					P[v[k].first][v[k].second] = 0;
				}

			}
		}
	}
	if (!turn) notSameProcess();
}
void turn(int x, bool d, int k) {
	for (int t = x; t <= N; t += x) {
		if (d) {
			//반시계
			for (int i = 0; i < k; i++) {
				int tmp = P[t][1];
				for (int j = 1; j < M; j++) {
					P[t][j] = P[t][j + 1];
				}
				P[t][M] = tmp;
			}
		}
		else {
			//시계
			for (int i = 0; i < k; i++) {
				int tmp = P[t][M];
				for (int j = M; j > 1; j--) {
					P[t][j] = P[t][j-1];
				}
				P[t][1] = tmp;
			}
		}
	}
	delnum();
}
int main() {
	PREPROCESS;
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> P[i][j];

	for (int i = 1; i <= T; i++)
		cin >> X[i] >> D[i] >> K[i];

	for (int i = 1; i <= T; i++) {
		turn(X[i], D[i], K[i]);
	}
	cout << answer() << '\n';
	return 0;
}
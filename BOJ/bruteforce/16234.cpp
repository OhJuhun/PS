#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321
int N, L, R;
int arr[51][51];
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
bool bfs() {
	bool visit[51][51];
	memset(visit, 0, sizeof(visit));
	bool flag = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visit[i][j]) continue;
			queue<pair<int, int>> q;
			queue<pair<int, int>> unions;
			int sumOfPeople = 0;
			//여기서 시작하는 모든 연합을 구한다
			q.push(make_pair(i, j));
			unions.push(make_pair(i, j));
			visit[i][j] = true;
			while (!q.empty()) {
				pair<int, int> c = q.front();
				q.pop();
				sumOfPeople += arr[c.first][c.second];
				for (int k = 0; k < 4; k++) {
					pair<int, int> n;
					n = make_pair(c.first + dir[k][0], c.second + dir[k][1]);
					if(n.first<1 || n.second<1 || n.first>N || n.second>N || visit[n.first][n.second] || //범위를 벗어나거나 방문해거나
						abs(arr[n.first][n.second]-arr[c.first][c.second])>R || abs(arr[n.first][n.second]-arr[c.first][c.second])<L) continue; //연합 조건에 미충족했을 경우
					visit[n.first][n.second] = true;
					q.push(n);
					unions.push(n);
				}
			}
			if (unions.size() == 1) continue;
			flag = true;
			int people = sumOfPeople / unions.size();
			while (!unions.empty()) {
				arr[unions.front().first][unions.front().second] = people;
				unions.pop();
			}
		}
	}
	return flag;
}
int solve() {
	int ret = 0;
	while (true) {
		if (!bfs()) break;
		ret++;
	}
	return ret;
}
void input() {
	cin >> N >> L >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}
int main() {
	PREPROCESS;
	input();
	cout << solve() << endl;
	return 0;
}
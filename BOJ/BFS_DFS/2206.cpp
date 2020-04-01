#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 987654321
char arr[1002][1002][2];
int n, m;
int ans = INF;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

struct item {
	int i, j,l;
	bool br;
};
int solution() {
	item it = { 1,1,1,1 };
	queue<item> q;
	q.push(it);

	while (!q.empty()) {
		item c = q.front();
		q.pop();
		if (c.i == n && c.j == m) return c.l;
		for (int i = 0; i < 4; i++) {
			item n = { c.i + dir[i][0],c.j + dir[i][1],c.l+1,c.br };
			if (arr[n.i][n.j][n.br]=='0') {
				//그냥 지나갈 수 있는 경우
				arr[n.i][n.j][n.br] = '2';
				q.push(n);
			}
			else if (arr[n.i][n.j][n.br]=='1' && n.br) {
				//그냥 지나갈 수 있고 부술수도 있는 경우
				n.br = false;
				arr[n.i][n.j][n.br] = '2';
				q.push(n);
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j][0];
			arr[i][j][1] = arr[i][j][0];
		}
	}
	
	for (int i = 0; i <= n + 1;i++) {
		arr[i][0][0] = '2';
		arr[i][m + 1][0] = '2';
		arr[i][0][1] = '2';
		arr[i][m + 1][1] = '2';
	}
	for (int j = 0; j <= m + 1; j++) {
		arr[0][j][0] = '2';
		arr[n + 1][j][0] = '2';
		arr[0][j][1] = '2';
		arr[n + 1][j][1] = '2';
	}
	cout << solution() << '\n';
}
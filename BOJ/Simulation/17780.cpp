#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

struct horse {
	int r, c, d;
	bool move = true;
};

int N, K;
int arr[13][13];
horse h[11];
vector<int> v[13][13];
int dir[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} };
int cnt = 0;

void white(int n, int x, int y) {
	//, x,y 갈 위치
	if (!v[x][y].empty()) {
		//해당 위치에 말이 있는 경우
		h[n].move = false;
	}
	int curx = h[n].r;
	int cury = h[n].c;
	for (int i = 0; i < v[curx][cury].size(); i++) {
		h[v[curx][cury][i]].r = x;
		h[v[curx][cury][i]].c = y;
		v[x][y].push_back(v[curx][cury][i]);
	}
	v[curx][cury].clear();
	cnt = max(cnt, (int)v[x][y].size());
}

void blue(int n) {
	//방향 변경
	switch (h[n].d) {
	case 1:
		h[n].d = 2;
		break;
	case 2:
		h[n].d = 1;
		break;
	case 3:
		h[n].d = 4;
		break;
	case 4:
		h[n].d = 3;
		break;
	}
}

int red(int n) {
	int x = h[n].r;
	int y = h[n].c;
	h[v[x][y][0]].move = false;
	stack<int> st;
	for (int i = 0; i < v[x][y].size(); i++) {
		st.push(v[x][y][i]);
	}
	v[x][y].clear();
	while (!st.empty()) {
		v[x][y].push_back(st.top());
		st.pop();
	}
	h[v[x][y][0]].move = true;
    n=v[x][y][0];
    return n;
}

void solve() {
	for (int i = 1; i <= K; i++) {
		if (!h[i].move) { //움직일 수 없는 말일 때
			continue;
		}
		int dr = dir[h[i].d][0];
		int dc = dir[h[i].d][1];
		int r = dr + h[i].r;
		int c = dc + h[i].c;
		if (r > 0 && c > 0 && r <= N && c <= N) {
			//범위에 속할 경우
			if (arr[r][c]==0) {
				white(i, r, c);
			}
			else if (arr[r][c] == 1) {
				int j=red(i);
				white(j, r, c);
			}
			else if(arr[r][c]==2) {
				blue(i);
				dr = dir[h[i].d][0];
				dc = dir[h[i].d][1];
				r = dr + h[i].r;
				c = dc + h[i].c;
				if (r > 0 && c > 0 && r <= N && c <= N) {
					if (arr[r][c] == 0)
						white(i, r, c);
					else if (arr[r][c] == 1) {
						int j=red(i);
						white(j,r, c);
					}
				}

			}
		}
		else {
			//범위에 속하지 않을 경우
			blue(i);
			dr = dir[h[i].d][0];
			dc = dir[h[i].d][1];
			r = dr + h[i].r;
			c = dc + h[i].c;
			if (r > 0 && c > 0 && r <= N && c <= N) {
				if (arr[r][c] == 0)
					white(i, r, c);
				else if (arr[r][c] == 1) {
					int j=red(i);
					white(j, r, c);
				}
			}
		}
	}
}
void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= K; i++) {
		cin >> h[i].r >> h[i].c >> h[i].d;
		v[h[i].r][h[i].c].push_back(i);
	}
}

int main() {
	PREPROCESS;
	input();

	int ans = 0;
	while (ans <= 1000 && cnt < 4) {
		solve();
		ans++;
	}
	cout << (ans <= 1000 ? ans : -1) << endl;
	return 0;
}
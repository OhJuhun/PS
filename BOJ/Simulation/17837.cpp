#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 98765432
struct horse {
	int r, c, d;
};
int N, K;
int arr[13][13];
int dir[5][2] = { {0,0}, {0,1},{0,-1},{-1,0},{1,0} };
horse h[10];
int len = 0;
vector<int> v[13][13];
 //x,y에서 r,c로 이동


void white(int X,int r,int c) {
	bool flag = false;
	vector<int> tmp;
	int x = h[X].r;
	int y = h[X].c;
	for (int i = 0; i < v[x][y].size(); i++) {
		if (v[x][y][i] == X) flag = true;
		if (!flag) {
			tmp.push_back(v[x][y][i]);
			continue;
		}
		h[v[x][y][i]].r = r;
		h[v[x][y][i]].c = c;
		v[r][c].push_back(v[x][y][i]);
	}
	v[x][y].clear();
	for (int i = 0; i < tmp.size(); i++)
		v[x][y].push_back(tmp[i]);
	len = max(len, (int)v[r][c].size());
}

int red(int X) {
	bool flag = false;
	vector<int> tmp;
	stack<int> st;
	int x = h[X].r;
	int y = h[X].c;
	for (int i = 0; i < v[x][y].size(); i++) {
		if (v[x][y][i] == X) flag = true;
		if (!flag) {
			tmp.push_back(v[x][y][i]);
			continue;
		}
		st.push(v[x][y][i]);
	}
	v[x][y].clear();
	for (int i = 0; i < tmp.size(); i++) {
		v[x][y].push_back(tmp[i]);
	}
	X = st.top(); //주체 변경
	while (!st.empty()) {
		v[x][y].push_back(st.top());
		st.pop();
	}

	return X;
}

int blue(int d) {
	if (d == 1) {
		d = 2;
	}
	else if (d == 2) {
		d = 1;
	}
	else if (d == 3) {
		d = 4;
	}
	else if (d == 4) {
		d = 3;
	}
	return d;
}
void solve() {
	for (int i = 0; i < K; i++) {
		if (len >= 4) return;
		horse next = h[i];
		next.r += dir[next.d][0];
		next.c += dir[next.d][1];
		
		if (next.r >= 1 && next.c >= 1 && next.r <= N && next.c <= N) {
			//범위 내
			if (arr[next.r][next.c] == 0) {
				white(i, next.r, next.c);
			}
			else if (arr[next.r][next.c] == 1) {
				int j = red(i);
				white(j, next.r, next.c); //도달하려는 곳은 바뀌지 않았으니까 가능해
			}
			else if (arr[next.r][next.c] == 2) {
				//방향 변경
				next.d = blue(next.d);
				next.r = h[i].r + dir[next.d][0];
				next.c = h[i].c + dir[next.d][1];
				h[i].d = next.d;
				if (next.r >= 1 && next.c >= 1 && next.r <= N && next.c <= N) {
					//바꾼 도달 위치도 범위 내
					if (arr[next.r][next.c] == 0) white(i, next.r, next.c);
					else if (arr[next.r][next.c] == 1) {
						int j = red(i);
						white(j, next.r, next.c);
					}
				}
			}
		}
		else {
			//범위 밖
			next.d = blue(next.d);
			next.r = h[i].r + dir[next.d][0];
			next.c = h[i].c + dir[next.d][1];
			h[i].d = next.d;
			if (next.r >= 1 && next.c >= 1 && next.r <= N && next.c <= N) {
				if (arr[next.r][next.c] == 0) white(i, next.r, next.c);
				else if (arr[next.r][next.c] == 1) {
					int j = red(i);
					white(j, next.r, next.c);
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
	for (int i = 0; i < K; i++) {
		cin >> h[i].r >> h[i].c >> h[i].d;
		v[h[i].r][h[i].c].push_back(i);
	}
}
int main() {
	PREPROCESS;
	input();
	int cnt = 0;
	while (cnt <= 1000 && len<4) {
		cnt++;
		solve();
	}
	cout << (cnt <= 1000 ? cnt : -1) << '\n';
	return 0;
}
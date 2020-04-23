#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321
struct item {
	int x, y, c, p;
};
int M, A;
int mo[2][101];
int dir[5][2] = { {0,0},{0,-1},{1,0},{0,1},{-1,0} };
//4일때 x감소
//2일때 x증가
//1일때 y감소
//3일떄 y 증가
item it[9];
int select(int x, int y, int r, int c) {
	vector<int> candA;
	vector<int> candB;
	for (int i = 1; i <= A; i++) {
		if (abs(x - it[i].x) + abs(y - it[i].y) <= it[i].c) candA.push_back(i);
		if (abs(r - it[i].x) + abs(c - it[i].y) <= it[i].c) candB.push_back(i);
	}

	int ret = 0;
	for (int i : candA) {
		for (int j : candB) {
			if (i == j) {
				//같은 것을 고른 경우
				ret = max(it[i].p, ret);
			}
			else
				ret = max(ret, it[i].p + it[j].p);
		}
	}
	//cout << candA.size() << " " << candB.size() << " ";
	if (candA.empty()) {
		for (int i : candB)
			ret = max(it[i].p, ret);
	}
	else if (candB.empty()) {
		for (int i : candA) {
			ret = max(it[i].p, ret);
		}
	}
	return ret;
}
int solve() {
	int ans = 0;
	int x[2], y[2];
	x[0] = y[0] = 1;
	x[1] = y[1] = 10;
	ans += select(x[0], y[0], x[1], y[1]);
	for (int i = 1; i <= M; i++) {
		x[0] += dir[mo[0][i]][0];
		x[1] += dir[mo[1][i]][0];
		y[0] += dir[mo[0][i]][1];
		y[1] += dir[mo[1][i]][1];
		ans+=select(x[0], y[0], x[1], y[1]);
	}
	return ans;
}
void input() {
	cin >> M >> A;
	memset(mo, 0, sizeof(mo));
	memset(it, 0, sizeof(it));
	for (int i = 0; i <2; i++) {
		for (int j = 1; j <= M; j++)
			cin >> mo[i][j];
	}
	for (int i = 1; i <= A; i++)
		cin >> it[i].x >> it[i].y >> it[i].c >> it[i].p;

}
int main() {
	PREPROCESS;
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		input();
		cout<<"#"<<i<<" "<<solve()<<'\n';
	}
	return 0;
}
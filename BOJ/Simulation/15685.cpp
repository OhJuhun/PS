#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321
struct curve {
	int x, y, g;
	vector<int> d;
};
int N;
curve curves[21];
int dir[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
bool arr[101][101];
int ans = 0;
int changeDir(int d) {
	return (d + 1) % 4;
}
void makeDir(int idx) {
	//j세대 드래곤 커브를 만듬

	int _size = curves[idx].d.size();
	for (int i = _size-1; i >= 0; i--) {
		curves[idx].d.push_back(changeDir(curves[idx].d[i]));
	}
}
void move(int idx) {
	for (int i :  curves[idx].d) {
		curves[idx].x += dir[i][1];
		curves[idx].y += dir[i][0];
		arr[curves[idx].y][curves[idx].x] = 1;
	}
}
void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < curves[i].g; j++) {
			makeDir(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		move(i);
	}
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (arr[i][j] == 0 ) continue;
			if (arr[i][j + 1] && arr[i + 1][j] && arr[i + 1][j + 1]) ans++;
		}
	}
}
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int d;
		cin >> curves[i].x >> curves[i].y >> d >> curves[i].g;
		arr[curves[i].y][curves[i].x] = 1;
		curves[i].d.push_back(d);
	}
}
int main() {
	PREPROCESS;
	input();
	solve();
	cout << ans << '\n';
	return 0;
}
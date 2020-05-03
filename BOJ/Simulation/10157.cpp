#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define INF 987654321
int arr[1000][1000];
int C, R, K;
int dir[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
bool solve() {
	if (C*R < K) return false;
	int number = 1;
	int d = 0;
	int i = R - 1, j = 0;
	while (number < K) {
		//현재위치를 먼저 채운다
		arr[i][j] = number++;
		/*cout << (i + dir[d][0] >= 0 && i + dir[d][0] < R && j + dir[d][1] >= 0 && j + dir[d][1] < C &&
			arr[i + dir[d][0]][j + dir[d][1]] == 0);*/
		if (!(i + dir[d][0] >= 0 && i + dir[d][0] < R && j + dir[d][1] >= 0 && j + dir[d][1] < C &&
			arr[i + dir[d][0]][j + dir[d][1]]==0)) //이동할 수 있는 곳이면 이동
			++d, d %= 4;
			i += dir[d][0], j += dir[d][1];
	}
	cout << j+1 << " " << R-i << endl;
	return true;
}
void input() {
	cin >> C >> R>>K;
	
}
int main() {
	PREPROCESS;
	input();
	if (!solve()) cout << 0 << endl;
	return 0;
}
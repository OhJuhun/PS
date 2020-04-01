#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <queue>
using namespace std;

int dice[6] = { 0,0,0,0,0,0 };

void dicing(int dir) {
	int tmp;
	switch (dir) {
	case 1:
		tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
		break;
	case 2:
		tmp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
		break;
	case 3:
		tmp = dice[0];
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
		break;
	case 4:
		tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
		break;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int arr[21][21];
	int cmd;
	int n, m, x, y, k;
	//0 - 5  1 - 4  2 -3
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int top = 0;//윗면이 0번
	for (int i = 0; i < k; i++) {
		cin >> cmd;
		//1 동 2 서 3 북 4 남
		bool print = true;
		switch (cmd) {
		case 1:
			if (y + 1 < m) {
				y++;
			}
			else print = false;
			break;
		case 2:
			if (y - 1 >= 0) {
				y--;
			}
			else print = false;
			break;
		case 3:
			if (x - 1 >= 0) {
				x--;
			}
			else print = false;
			break;
		case 4:
			if (x + 1 < n) {
				x++;
			}
			else print = false;
			break;
		}
		if (print) {
			dicing(cmd);
			if (arr[x][y] == 0) {
				arr[x][y]=dice[5];
			}
			else {
				dice[5] = arr[x][y];
				arr[x][y] = 0;
			}
			cout << dice[0] << "\n";
		}
	}

	return 0;
}
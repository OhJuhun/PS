#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int N;
int arr[21][21];
int division[21][21];
int ans = MAX;
int ALL = 0;
void make_div(int x, int y, int d1, int d2) {
	
	for (int i = 0; i <= d1; i++) {
		division[x + i][y - i] = 5; //1
		division[x + d2+i][y + d2-i] = 5; //4
	}
	for (int i = 0; i <= d2; i++) {
		division[x + i][y + i] = 5; //2
		division[x + d1 + i][y - d1 + i] = 5; //3
	}

	
}
void answer(int x, int y, int d1, int d2) {
	int a=0, b=0, c=0, d=0, e=0;
	memset(division, 0, sizeof(division));
	make_div(x, y, d1, d2);
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			if (!division[r][c] && 1 <= r && r < x + d1 && 1 <= c && c <= y) {
				division[r][c] = 1;
			}
			else if (!division[r][c] && 1 <= r && r <= x + d2 && y < c && c <= N) {
				division[r][c] = 2;
			}
			else if (!division[r][c] && x + d1 <= r && r <= N && 1 <= c && c < y - d1 + d2) {
				division[r][c] = 3;
			}
			else if (!division[r][c] && x + d2 < r && r <= N && y - d1 + d2 <= c && c <= N) {
				division[r][c] = 4;
			}
			else {
				division[r][c] = 5;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			//a구하기
			if (division[i][j] == 1)
				a += arr[i][j];
			else break;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = N; j > 0; j--) {
			if (division[i][j] == 2)
				b += arr[i][j];
			else break;
		}
	}

	for (int i = N; i > 0; i--) {
		for (int j = 1; j <= N; j++) {
			if (division[i][j] == 3)
				c += arr[i][j];
			else break;
		}
	}
	for (int i = N; i > 0; i--) {
		for (int j = N; j > 0; j--) {
			if(division[i][j]==4)
				d += arr[i][j];
			else break;
		}
	}
	e = ALL - (a + b + c + d);
	int M = max(a, max(b, max(c, max(d, e))));
	int m = min(a, min(b, min(c, min(d, e))));
	
	ans = min(ans,M - m);
	
}
void setxyd() {
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			for (int d1 = 1; d1 <= N; d1++) {
				for (int d2 = 1; d2 <= N; d2++) {
					if (x + d1 + d2 <= N && y - d1 >= 1 && y + d2 <= N) {
						answer(x, y, d1, d2);
					}

				}
			}
		}
	}
}
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			ALL += arr[i][j];
		}
	}
}
int main() {
	PREPROCESS;
	input();
	setxyd();
	cout << ans << endl;

}
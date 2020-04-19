
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 98765432
struct item {
	int r, sc, ec; //현재 높이, 시작, 끝 
};
item it[2];
int N, M, C;
int arr[11][11];
int answer;
bool arr2[5];
bool arr3[5];

void dfs2(int t, int T,int _sum) {
	if (t == T) {
		int sum = 0;
		int s = _sum;
		for (int i = it[1].sc; i <= it[1].ec; i++) {

			if (arr3[i - it[1].sc]) {
				sum += arr[it[1].r][i];
				_sum += arr[it[1].r][i] * arr[it[1].r][i];
			}
		}
		if (sum <= C) {
			answer = max(answer, _sum);
		}
		return;
	}
	for (int i = 0; i < 2; i++) {
		arr3[t] = i;
		dfs2(t + 1, T, _sum);
	}
}
void dfs(int t, int T) {
	if (t == T) {
		int sum = 0;
		int _sum = 0;
		for (int i = it[0].sc; i <= it[0].ec; i++) {
			if (arr2[i - it[0].sc]) {
				sum += arr[it[0].r][i];
				_sum += arr[it[0].r][i] * arr[it[0].r][i];
			}
		}
		if (sum <= C) dfs2(0, M,_sum);
		return;
	}
	for (int i = 0; i < 2; i++) {
		arr2[t] = i;
		dfs(t + 1, T);
	}
}
void calc() {
	memset(arr2, 0, sizeof(arr2));
	memset(arr3, 0, sizeof(arr3));
	dfs(0, M);
}
void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N - M+1; j++) {
			it[0].r = i;
			it[0].sc = j;
			it[0].ec = j + M - 1;
			//처음 사람의 위치 선정
			for (int k = i; k <= N; k++) {
				for (int l = 1; l <= N - M + 1; l++) {
					it[1].r = k;
					it[1].sc = l;
					it[1].ec = l + M - 1;
					if (it[0].r==it[1].r && it[1].sc <= it[0].ec) continue;
					if (it[1].ec > N) break;
					//범위를 벗어날 경우 break
					calc();
				}
			}
		}
	}
}
void input() {
	memset(arr, 0, sizeof(arr));
	answer = 0;
	cin >> N >> M >> C;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
}
int main() {
	PREPROCESS;
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		input();
		solve();
		cout << "#" << i << " " << answer << '\n';
	}
	return 0;
}
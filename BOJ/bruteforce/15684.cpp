#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321
int N, M, H;
int answer = 9999;
bool arr[31][11];

bool judge() {
	bool flag = true;
	for (int j = 1; j <= N; j++) {
		int cur = j;
		for (int i = 1; i <= H; i++) {
			if (arr[i][cur]) cur = cur + 1;
			else if (arr[i][cur - 1]) cur = cur - 1;
		}
		if (cur != j) {
			return false;
		}
	}
	return true;
}

void dfs(int t,int r) {
	bool flag = judge();
	//들어올 때마다 확인
	if (flag) {
		answer = min(answer, t);
		return;
	}
	if (t == 3) {
		return; //3개째이면 끝냄
	}
	for (int i = r; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] || arr[i][j - 1] || arr[i][j + 1]) continue;
			arr[i][j] = true;
			dfs(t + 1, i);
			arr[i][j] = false;
		}
	}

}
void solve() {
	dfs(0,1);
}

void input() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1; //a번 라인에 b와 b+1이 연결되어 있다
	}
}
int main() {
	PREPROCESS;
	input();
	solve();
	cout << (answer==9999 ? -1 :answer)<< endl;
	return 0;
}
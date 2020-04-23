#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321
int N;
struct atom {
	int y, x, K,d;
	bool boom = false;
};
atom a[1001];
int arr[4004][4004]; 
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
int ans;

bool checkDir(int i,int j) {
	if (a[i].d == 0) {
		return a[j].d == 1;
	}
	else if (a[i].d == 1) {
		return a[j].d == 0;
	}
	else if (a[i].d == 2) {
		return a[j].d == 3;
	}
	else if (a[i].d == 3) {
		return a[j].d == 2;
	}
}
void solve() {
	for (int i = 1; i <= N; i++) {
		if (a[i].K == -1) continue;
		arr[a[i].y][a[i].x] = 0;
		a[i].x += dir[a[i].d][1];
		a[i].y += dir[a[i].d][0];
		if (a[i].x > 4003 || a[i].x < 0 || a[i].y>4003 || a[i].y < 0) {
			a[i].K = -1;
			continue;
		}
		if (arr[a[i].y][a[i].x]!=0) {
			//가려는 곳이 비어있지 않다
			if (arr[a[i].y][a[i].x] > i) {
				//가려는 곳이 나보다 크면 아직 이동을 안한 상태임
				//true이면 나에게 오는 중이므로 바로 터트림
				if (checkDir(i,arr[a[i].y][a[i].x])) {
					//가려는 곳이나에게 오고있다
					ans += a[i].K + a[arr[a[i].y][a[i].x]].K;
					a[arr[a[i].y][a[i].x]].K = -1;
					a[i].K = -1;
					arr[a[i].y][a[i].x] = 0; //그곳을 비우고 터뜨림
					continue;
				}
			}
			else {
				//아니면 이동을 햇으니 그냥 boom!
				arr[a[i].y][a[i].x] = -1; 
			}
		}
		else {
			arr[a[i].y][a[i].x] = i;
		}
	}
	queue<pair<int, int>> q;
	for (int i = 1; i <= N; i++) {
		if (a[i].K == -1) continue;
		if (arr[a[i].y][a[i].x] == -1) {
			//터진 곳 
			ans += a[i].K;
			a[i].K = -1;
			q.push(make_pair(a[i].y, a[i].x));
		}
	}
	while (!q.empty()) {
		arr[q.front().first][q.front().second] = 0;
		q.pop();
	}
}
void input() {
	cin >> N;
	ans = 0;
	memset(a, 0, sizeof(a));
	memset(arr, 0, sizeof(arr));
	for (int i = 1; i <= N; i++) {
		cin >> a[i].x >> a[i].y >> a[i].d >> a[i].K;
        a[i].x*=2;
        a[i].y*=2;
		a[i].x += 2000;
		a[i].y += 2000;
		arr[a[i].y][a[i].x] = i;
	}
}
int main() {
	PREPROCESS;
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		input();
		while(true){
			solve();
			bool flag = true;
			for (int i = 1; i <= N; i++) {
				if (a[i].K != -1) {
					flag = false;
				}
			}
			if (flag) break;
		}
		cout << "#" << i << " " << ans << '\n';
	}
	return 0;
}
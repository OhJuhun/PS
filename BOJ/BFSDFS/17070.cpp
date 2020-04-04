#include <iostream>
#include <vector>
using namespace std;

bool arr[17][17]; //!!!배열 초기화!!!
bool visit[17][17] = { false };
int N;
int ans = 0;
bool goRight(pair<int,int> head) {
	if (!arr[head.first][head.second + 1] && head.second + 1 < N + 1) {
		//방문가능하면
		return true;
	}
	return false;
}
bool goRD(pair<int, int> head) {
	if (!arr[head.first + 1][head.second + 1] && !arr[head.first][head.second + 1] &&
		!arr[head.first + 1][head.second] && head.second + 1 < N + 1 && head.first + 1 < N + 1) {
		return true;
	}

	return false;
}
bool goDown(pair<int, int>head) {
	if(!arr[head.first + 1][head.second] && head.first+1<N+1) return true;
	return false;
}

void dfs(pair<int,int> tail,pair<int,int> head) {
	if (head.first == N && head.second == N) {
		ans++;
		return;
	}
	if (head.first - tail.first == 0 && head.second - tail.second == 1) {
		if (goRight(head)) {
			dfs( head, { head.first,head.second + 1 });
		}
		if (goRD(head)) {
			dfs(head, { head.first + 1,head.second + 1 });
		}
	}// 가로방향으로 있는 경우
	else if (head.first - tail.first == 1 && head.second - tail.second == 0) {
		if (goRD(head)) {
			dfs(head, { head.first + 1,head.second + 1 });
		}
		if (goDown(head)) {
			dfs(head, { head.first+1,head.second });
		}


	}//세로방향으로 있는 경우
	else if (head.first - tail.first == 1 && head.second - tail.second == 1) {
		if (!arr[head.first + 1][head.second] && head.first+1<N+1) {
			dfs(head, { head.first + 1,head.second });
		}
		if (!arr[head.first + 1][head.second + 1] && head.first+1<N+1 && head.second+1<N+1 && !arr[head.first + 1][head.second] && !arr[head.first][head.second + 1] && head.second+1) {
			dfs(head, { head.first + 1,head.second + 1 });
		}
		if (!arr[head.first][head.second + 1] && head.second+1 <N+1) {
			dfs(head, { head.first,head.second + 1 });
		}
	}//대각으로 있는경우
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	pair<int, int> tail, head;
	tail.first = 1;
	tail.second = 1;
	head.first = 1;
	head.second = 2;
	dfs(tail, head);
	cout << ans << endl;
	return 0;

}
#include <iostream>
#include <algorithm>
using namespace std;

int start[501][501]; //각 시작점
int arr[501][501];
int n,m=-1;
int cnt = 0;

int dfs(int x, int y) { //경로를 찾는다. 메모이제이션만쓰면댐
	cnt++;
	if (start[x][y] != -1)
		return start[x][y]; //이미 방문
	start[x][y] = 1;
	if (arr[x][y] < arr[x + 1][y] && x + 1 <= n) { //현재점보다 목적지가 더 크다면
		start[x][y] = max(start[x][y], dfs(x + 1, y) + 1); //다음점 확인 및 메모

	}
	if (arr[x][y] < arr[x - 1][y] && x - 1>0) {
		start[x][y] = max(start[x][y], dfs(x - 1, y) + 1);

	}
	if (arr[x][y] < arr[x][y + 1] && y + 1 <= n) {
		start[x][y] = max(start[x][y], dfs(x, y + 1) + 1);

	}
	if (arr[x][y] < arr[x][y - 1] && y - 1>0) {
		start[x][y] = max(start[x][y], dfs(x, y - 1) + 1);

	}
	if (m < start[x][y])
		m = start[x][y];
	return start[x][y];
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			start[i][j] = -1; //시작점은 1day로 초기화
		}
	} //대나무의 양입력

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			m=max(m,dfs(i, j));
		//	cout << start[i][j] << " ";
		}
	//	cout << endl;
	}
	cout << m << endl;
//	cout << "cnt:" << cnt << endl;
	return 0;
}
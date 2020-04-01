#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>

using namespace std;

int N;
int ans = 0;
int chess[20][20]; //대각 확인용

void setArr(int i, int j) {
	//i,j부터 대각선 가로 세로를 다 채움
	for (int k = 1; k <= N; k++) //가로
		chess[i][k] ++;
	for (int k = 1; k <= N; k++) //세로
		chess[k][j] ++;

	int tmpi = i;
	int tmpj = j;
	while (tmpj > 0 && tmpi > 0) chess[tmpi--][tmpj--] ++;
	tmpi = i;
	tmpj = j;
	while (tmpj <= N && tmpi <= N) chess[tmpi++][tmpj++] ++;
	tmpi = i;
	tmpj = j;
	while (tmpj > 0 && tmpi <= N) chess[tmpi++][tmpj--] ++;
	tmpi = i;
	tmpj = j;
	while (tmpj <= N && tmpi > 0) chess[tmpi--][tmpj++] ++;
	chess[i][j] -= 5;
	//세팅 완료
}

void back(int i, int j) {
	//i,j부터 대각선 가로 세로를 다 채움
	for (int k = 1; k <= N; k++) //가로
		chess[i][k] --;
	for (int k = 1; k <= N; k++) //세로
		chess[k][j] --;

	int tmpi = i;
	int tmpj = j;
	while (tmpj > 0 && tmpi > 0) chess[tmpi--][tmpj--] --;
	tmpi = i;
	tmpj = j;
	while (tmpj <= N && tmpi <= N) chess[tmpi++][tmpj++] --;
	tmpi = i;
	tmpj = j;
	while (tmpj > 0 && tmpi <= N) chess[tmpi++][tmpj--] --;
	tmpi = i;
	tmpj = j;
	while (tmpj <= N && tmpi > 0) chess[tmpi--][tmpj++] --;
	chess[i][j] += 5;
}
void init() {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j<= N; j++) {
			chess[i][j] = false;
		}
	}
}
void dfs(int i) {
	for (int j = 1; j <= N; j++) {
		if (chess[i][j] == 0) {
			//퀸을 추가할 수 있는 구역이면
			if (N == i) {
				ans++; //마지막 줄인지 확인후 맞으면 정답 증가
				continue;
			}
			setArr(i, j);
			dfs(i + 1);
			back(i, j);
		}
	}
}
int getAnswer() {
	
	for (int i = 1; i <= N; i++) {
		setArr(1, i); //가로, 세로, 대각선을 모두 1로 채움
		dfs(2);
		back(1,i);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N;
	if (N == 1) cout << 1 << '\n';
	else
		cout << getAnswer() << '\n';
}

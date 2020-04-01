#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int N, L;
int arr[101][101];
bool rows[101];
bool cols[101];
bool bridge[101];
void input() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
}

bool calcRow(int r) {
	int len = 1; //현재까지의 길이

	for (int i = 1; i < N; i++) {
		if (abs(arr[r][i] - arr[r][i - 1]) > 1) return false; //높이차이가 2이상 날 경우
		if (arr[r][i] == arr[r][i - 1]) {
			//이전과 값이 같으면 len++
			len++;
		}
		else if (arr[r][i] - arr[r][i - 1] > 0) {
			//다음에 올 높이가 더 높은 경우
			if (len < L) {
				//경사로의 길이가 더 길면 안됨
				return false;
			}
			//len<L이라면 L만큼의 경사로를 설치해야함
			for (int j = 1; j <= L; j++) {
				if (bridge[i - j]) {
					return false; //이미 설치된 곳이라면 겹칠수 없으므로 ㅃㅃ
				}
				bridge[i-j] = true;
			}
			//설치를 끝냈음
			
		}
		else {
			//다음에 올 높이가 더 낮은 경우
			for (int j = 0; j < L; j++) {
				if (j + i >= N) return false;
				if (arr[r][j + i] != arr[r][i]) {
					return false;
				}
			}
			len = 0;
			i = i + L-1;
		}
	}

	return true;
}

bool calcCol(int c) {
	int len = 1; //현재까지의 길이

	for (int i = 1; i < N; i++) {
		if (abs(arr[i][c] - arr[i-1][c]) > 1) return false; //높이차이가 2이상 날 경우
		if (arr[i][c] == arr[i-1][c]) {
			//이전과 값이 같으면 len++
			len++;
		}
		else if (arr[i][c] - arr[i-1][c] > 0) {
			//다음에 올 높이가 더 높은 경우
			if (len < L) {
				//경사로의 길이가 더 길면 안됨
				return false;
			}
			//len<L이라면 L만큼의 경사로를 설치해야함
			for (int j = 1; j <= L; j++) {
				if (bridge[i - j]) {
					return false; //이미 설치된 곳이라면 겹칠수 없으므로 ㅃㅃ
				}
				bridge[i - j] = true;
			}
			//설치를 끝냈음

		}
		else {
			//다음에 올 높이가 더 낮은 경우
			for (int j = 0; j < L; j++) {
				if (j + i >= N) return false;
				if (arr[j+i][c] != arr[i][c]) {
					return false;
				}
			}
			len = 0;
			i = i + L-1;
		}
	}

	return true;
}
void solveRow() {
	for (int i = 0; i < N; i++) {
		bool flag = true;
		int front = arr[i][0];
		int mval = front;
		int midx = 0;
		for (int j = 1; j < N; j++) {
			if (arr[i][j] != front) {
				flag = false;
				if (arr[i][j] > mval)
					mval = arr[i][j], midx = j;
			}
		}
		if (flag) //모두 같은 값일 경우
			rows[i] = true;
		else {
			//모두 같은 값이 아닐 경우
			memset(bridge, false, sizeof(bridge));
			rows[i] = calcRow(i);
		}
	}
}


void solveCol() {
	for (int j = 0; j < N; j++) {
		bool flag = true;
		int front = arr[0][j];
		int mval = front;
		int midx = 0;
		for (int i = 1; i < N; i++) {
			if (arr[i][j] != front) {
				flag = false;
				if (arr[i][j] > mval)
					mval = arr[i][j], midx = i;
			}
		}
		if (flag) cols[j] = true;
		else {
			memset(bridge, false, sizeof(bridge));
			cols[j] = calcCol(j);
		}
	}
}
int findAns() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += rows[i] + cols[i];
	}
	return ans;
}
int getAnswer() {
	input();
	solveRow();
	solveCol();
	return findAns();
	
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	
	cout << getAnswer() << endl;
}
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 100000001
#define MIN -100000001

int arr[20][20];
int N, X;
int ans;

bool horizon(int r) {
	int cont = 1; //현재까지 연속된 수
	bool flag = false; //작아졌는가
	for (int j = 1; j < N; j++) {
		if (abs(arr[r][j] - arr[r][j - 1]) > 1) return false; //높이차이가 2이상일 경우 false
		if (flag) {
			//작아진 후 아직 다리를 건설하지 않았음
			if (cont == X) {
				flag = false;
				cont = 0;
			}
		}
		if (arr[r][j] == arr[r][j - 1]) { //이전이랑 높이가 같으면 cont 증가
			cont++;
		}
		else if (arr[r][j] == arr[r][j - 1] + 1) {
			//이전꺼보다 1 클 때
			if (flag) return false;
				//커졌는데 아직 flag가 남아있다
			if (cont >= X) {
				cont = 1;
			}
			else return false;
		}
		else if (arr[r][j] == arr[r][j - 1] - 1) {
			//이전보다 1 작아짐
			if (flag) return false;
			//작아졌는데 아직 flag가 남아잇음
			cont = 1;
			flag = true;
		}
	}
	if (flag) {
		//내려간 경우
		if (cont >= X)
			return true;
		else return false;
	}
	else
		return true;

}
bool vertical(int c) {
	int cont = 1;
	bool flag = false;
	for (int i = 1; i < N; i++) {
		if (abs(arr[i][c] - arr[i - 1][c]) > 1) {
			//높이차이가 2 이상일 경우 false
			return false;
		}
		if (flag) {
			//변경 경험이 있는 경우
			if (cont == X) {
				cont = 0;
				flag = false;
			}
		}
		if (arr[i][c] == arr[i - 1][c]) cont++;
		else if (arr[i][c] == arr[i - 1][c] + 1) {
			if (flag) return false;
			if (cont >= X)
				cont = 1;
			else return false;
		}
		else if (arr[i][c] == arr[i - 1][c] - 1) {
			if (flag) return false;
			cont = 1;
			flag = true;
		}
	}
	if (flag) {
		if (cont >= X) 
			return true;
		else return false;
	}
	else return true;
}
void solve() {
	for (int i = 0; i < N; i++) {
		bool can = true;
		for (int j = 0; j < N-1; j++) {
			if (arr[i][j] != arr[i][j + 1]) {
				can = false;
				break;
			}
		}
		if (can) {
			ans++;
		}
		else {
			//build bridge horizontal
			if (horizon(i)) {
				ans++;
			}
			
		}
	}
	for (int j = 0; j < N; j++) {
		bool can = true;
		for (int i = 0; i < N - 1; i++) {
			if (arr[i][j] != arr[i + 1][j]) {
				can = false;
				break;
			}
		}
		if (can) {
			ans++;
		}
		else {
			//build bridge vertical
			if (vertical(j)) {
				ans++;
			}
		}
	}
}
void input() {
	memset(arr, 0, sizeof(arr));
	ans = 0;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
}

int main() {
	PREPROCESS;

	int T;
	cin >> T;
	for (int t = 1; t <= T;t++) {
		input();
		solve();
		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}
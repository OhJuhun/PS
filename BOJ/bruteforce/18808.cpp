#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

struct sticker {
	int n, m; //사이즈
	int arr[10][10];
};
int N, M, K;
int notebook[41][41];
vector<sticker> v;
bool sticky(int r, int c, sticker s) {
	//r,c부터 시작해서 스티커를 붙일 수 있는지 판단한다
	if (r + s.n > N || c + s.m > M) return false; //노트북보다 커지면 return
	for (int i = r; i < r + s.n; i++) {
		for (int j = c; j < c + s.m; j++) {
			if (notebook[i][j] && s.arr[i-r][j-c]) return false; //둘 모두가 1이면 붙일 수 없는 곳이다.
		}
	}
	for (int i = r; i < r + s.n; i++) {
		for (int j = c; j < c + s.m; j++) {
			notebook[i][j] = s.arr[i - r][j - c] + notebook[i][j];//스티커를 붙인다.
		}
	}
	return true;
}

void turn(int s) {
	sticker ret;
	ret.n = v[s].m;
	ret.m = v[s].n;
	for (int i = 0; i < ret.n; i++) {
		for (int j = 0; j < ret.m; j++) {
			ret.arr[i][j] = v[s].arr[ret.m - j-1][i];
		}
	}

	v[s] = ret;
}

int solve() {
	for (int s = 0; s < v.size();s++) {
		//이번 스티커를 붙일 때
		bool isStick = false; //붙였으면 true로 변화하여 끝낸다.
		for (int t = 0; t < 4; t++) {
			//0일때 노회전
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
				//	if (notebook[i][j]) continue; //붙일 수 없는 곳이므로 끝낸다.
					isStick = sticky(i, j, v[s]); //현재 스티커를 붙일 수 잇는지 판단한다.
					if (isStick) break;
				}
				if (isStick) break;
			}
			if (isStick || t == 3) break;
			//붙이지 못한 경우
			turn(s); //스티커를 턴하고 다시 확인한다.
			
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += notebook[i][j];
		}
	}
	return ans;
}
void input() {
	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		sticker tmp;
		cin >> tmp.n >> tmp.m;
		for (int j = 0; j < tmp.n; j++) {
			for (int k = 0; k < tmp.m; k++) {
				cin >> tmp.arr[j][k];
			}
		}
		v.push_back(tmp);
	}
	
}
int main() {
	PREPROCESS;
	input();
	cout << solve() << endl;
	return 0;
}
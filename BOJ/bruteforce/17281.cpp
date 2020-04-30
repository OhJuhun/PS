#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int N;
int answer = 0;
int arr[51][10];
int order[10]; // order[i]번 선수가 i번 타자!
void solve() {
	for (int i = 1; i <= 9; i++) {
		order[i] = i;
	}
	int ans = 0;
	do {
		if (order[4] != 1) continue;
		int score = 0;
		int startN = 1;
		for (int i = 1; i <= N; i++) { //이닝
			bool rus[5] = { 0,0,0,0,0 };
			int outs = 0;
			while (outs < 3) {
				if (arr[i][order[startN]] == 0) {
					outs++;
				}
				else if (arr[i][order[startN]] == 1) {
					if (rus[3]) {
						rus[3] = 0, score++;
					}
					if (rus[2]) {
						rus[2] = 0, rus[3] = 1;
					}
					if (rus[1]) {
						rus[1] = 0, rus[2] = 1;
					}
					rus[1] = 1;
				}
				else if (arr[i][order[startN]] == 2) {
					if (rus[3]) {
						rus[3] = 0, score++;
					}
					if (rus[2]) {
						rus[2] = 0, score++;
					}
					if (rus[1]) {
						rus[3] = 1;
						rus[1] = 0;
					}
					rus[2] = 1;
				}
				else if (arr[i][order[startN]] == 3) {
					if (rus[3]) {
						rus[3] = 0, score++;
					}
					if (rus[2]) {
						rus[2] = 0, score++;
					}
					if (rus[1]) {
						rus[1] = 0, score++;
					}
					rus[3] = 1;
				}
				else if (arr[i][order[startN]] == 4) {
					int cnt = 1;
					for (int i = 1; i <= 3; i++) {
						if (rus[i]) cnt++;
						rus[i] = 0;
					}
					score += cnt;
				}
				startN++;
				if (startN == 10) startN = 1;
			}
		}
		answer = max(score, answer);
	} while (next_permutation(order + 1, order + 10));
}
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 9; j++)
			cin >> arr[i][j];
	}

}
int main() {
	PREPROCESS;
	input();
	solve();
	cout << answer << endl;
	return 0;
}
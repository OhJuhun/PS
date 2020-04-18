#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 98765432

int price[4];
int plan[12];
int arr[12];
int answer;
void dfs(int t) {
	if (t == 12) {
		int ans = 0;
		for (int i = 0; i < 12; i++) {
			if (arr[i] == 0) {
				ans += plan[i] * price[0];
			}
			else if (arr[i] == 1) {
				ans += price[1];
			}
			else if (arr[i] == 2) {
				ans += price[2];
				i += 2;
			}
		}
		answer = min(ans, answer);
		return;
	}
	for (int i = 0; i < 3; i++) {
		arr[t] = i;
		dfs(t+1);
	}
}
void solve() {
	dfs(0);
}
void input() {
	for (int i = 0; i < 4; i++)
		cin >> price[i]; //일,달,3달,12달
	for (int i = 0; i < 12; i++)
		cin >> plan[i];
	answer = price[3];

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
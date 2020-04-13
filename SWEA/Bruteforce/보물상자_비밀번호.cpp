#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321
int N, K;
string HEX;
set<long long> nums;

void turn() {
	char tmp = HEX[HEX.length() - 1];
	for (int i = HEX.length() - 1; i > 0; i--) {
		HEX[i] = HEX[i - 1];
	}
	HEX[0] = tmp;
}
void htod(string str) {
	int h = N / 4;
	long long dec = 0;
	long long mul = 1;
	for (int i = h - 1; i >= 0; i--) {
		if(str[i]>='0' && str[i]<='9')
			dec += (mul*(str[i] - '0'));
		else if (str[i] == 'A')	dec += 10 * mul;
		else if (str[i] == 'B') dec += 11 * mul;
		else if (str[i] == 'C') dec += 12 * mul;
		else if (str[i] == 'D') dec += 13 * mul;
		else if (str[i] == 'E') dec += 14 * mul;
		else if (str[i] == 'F') dec += 15 * mul;
		mul *= 16;
		//cout << dec << endl;
	}
	nums.insert(dec);

}
void solve() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i += N / 4) {
			htod(HEX.substr(i, N / 4));
		}
		turn();
	}
}
void input() {
	nums.clear();
	cin >> N >> K;
	cin >> HEX; //16진수로 입력
}
int main() {
	PREPROCESS;
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		input();
		solve();
		int mini = 0;
		long long ans;
		for (long long j : nums) {
			mini++;
			if (nums.size() - mini == K-1) ans = j;
		}
		cout << "#" << i << " " << ans << '\n';
	}
	return 0;
}
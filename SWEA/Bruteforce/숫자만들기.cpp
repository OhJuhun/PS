#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 100000001
#define MIN -100000001

int N;
int opers[4];
int nums[15];
int big;
int small;
const char op[4] = { '+','-','*','/' };
string operators;
void solve(){

	do {
		int tmp;
		if(operators[0]=='+'){
			tmp = nums[0] + nums[1];
		}
		if (operators[0] == '-') {
			tmp = nums[0] - nums[1];
		}
		if (operators[0] == '*') {
			tmp = nums[0] * nums[1];
		}
		if (operators[0] == '/') {
			tmp = nums[0] / nums[1];
		}
		for (int i = 1; i < N - 1; i++) {
			switch (operators[i]) {
			case '+':
				tmp += nums[i + 1];
				break;
			case '-':
				tmp -= nums[i + 1];
				break;
			case '*':
				tmp *= nums[i + 1];
				break;
			case '/':
				tmp /= nums[i + 1];
				break;
			}
		}
		big = max(big, tmp);
		small = min(small, tmp);
	} while (next_permutation(operators.begin(), operators.end()));
}
void input() {
	cin >> N;
	memset(nums, 0, sizeof(nums));
	operators = "";
	big = MIN;
	small = MAX;
	for (int i = 0; i < 4; i++)
		cin >> opers[i];
	for (int i = 0; i < N; i++)
		cin >> nums[i];
	for(int i=0;i<4;i++)
		for (int j = 0; j < opers[i]; j++) 
			operators += op[i];
	sort(operators.begin(), operators.end());
}
int main() {
	PREPROCESS;

	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		input();
		solve();
		cout << "#" << i << " " << big - small << '\n';

	}
	return 0;
}
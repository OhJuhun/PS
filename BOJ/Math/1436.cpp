#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	int i = 0;
	int cnt = 0;
	while (++i) {
		int tmp = i, flag = 0;
		while (tmp) {
			if (tmp % 1000 == 666) flag = 1;
			tmp /= 10;
		}
		if (flag) {
			cnt++;
			if (cnt == N) break;
		}
	}
	cout << i << endl;
	return 0;
}
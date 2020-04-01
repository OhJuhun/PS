#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


int N, R, C;
int ans = 0;
void answer(int r, int c, int size) {
	if (size == 2) {
		if (C == c && R == r) {
			//ans++;
			cout << ans << endl;
		}
		else if (C == c + 1 && R == r) {
			ans += 1;
			cout << ans << endl;
		}
		else if (C == c && R == r + 1) {
			ans += 2;
			cout << ans << endl;
		}
		else if (C == c + 1 && R == r + 1) {
			ans += 3;
			cout << ans << endl;
		}
		else {
			ans += 4;
		}
		return;
	}
	answer(r, c, size / 2);
	answer(r, c + size / 2 , size / 2);
	answer(r+size / 2, c, size / 2);
	answer(r+(size) / 2, c+(size) / 2, size / 2);
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> R >> C;
	answer(0, 0, 1 << N);

	return 0;
}
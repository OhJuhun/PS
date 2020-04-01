#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int tri[1001];
int main() {
	int n;
	cin >> n;
	int k = 1;
	for (int i = 2; k <= 1000; i++) {
		tri[i-2] = k;
		k += i;
	}
	while (n--) {
		int a;
		cin >> a;
		bool ans = false;
		for (int i = 0; i < 44; i++) {
			for (int j = 0; j < 44; j++) {
				for (int k = 0; k < 44; k++) {
					if (tri[i] + tri[j] + tri[k] == a) {
						ans = true;
					}
					if (ans) break;
				}
				if (ans)break;
			}
			if (ans) break;
		}
		cout << ans << '\n';
	}
}
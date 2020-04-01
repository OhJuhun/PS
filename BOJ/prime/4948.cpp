#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool prime[123456*2+2];
void eratos() {
	for (int i = 2; i <= sqrt(123456*2+2);i++) {
		if (!prime[i]) { //false이면 prime
			for (int j = i + i; j <= 123456*2+2; j += i) {
				prime[j] = true; //prime이 아님
			}
		}
	}
}
int main() {
	
	vector<int> v;
	eratos();
	prime[1] = true;
	while (true) {
		int n;
		cin >> n;
		if (!n) return 0;
		int ans = 0;
		for (int i = 1 + n; i <= 2 * n; i++) {
			if (!prime[i]) ans++;
		}
		cout << ans << '\n';
	}
	
}
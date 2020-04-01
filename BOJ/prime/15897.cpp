#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;
	long long ans = 0;
	int j = 0;
	for (int i = 1; i <= n; i += j) {
		if ((n - 1) / i == 0) {
			j = 1;
		}
		else
			j = ((n - 1) % i) / ((n - 1) / i) + 1;
		ans += (1 + (n - 1) / i)*j;
	}

	cout << ans << endl;
}
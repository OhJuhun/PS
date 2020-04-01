#include <algorithm>
#include <iostream>

using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		long long n, stock[1000001];
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> stock[i];
		long long mx = 0;
		long long ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			mx = max(mx, stock[i]);
			if (mx > stock[i])
				ans += mx - stock[i];
		}
		cout << ans << '\n';
	}

	return 0;
}
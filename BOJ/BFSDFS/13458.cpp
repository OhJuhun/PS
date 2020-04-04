#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, b, c;
int arr[1000001];
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;
	long long ans = n;
	for (int i = 0; i < n; i++) {
		arr[i] -= b;
		if (arr[i] > 0) {
			ans += arr[i] / c;
			if (arr[i] % c != 0)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
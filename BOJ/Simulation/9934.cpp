#include <iostream>
#include <algorithm>

using namespace std;

int tree[(1 << 11)+1];
int k,n;

int arr[(1 << 11) + 1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> k;
	n = (1 << k);
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
	}
	int node = n / 2;
	int mul = n;
	while (mul>1) {
		for (int i = node; i <= n; i+=mul) {
			cout << arr[i] << " ";
		}
		cout << endl;
		mul /= 2;
		node /= 2;
	}
	
	return 0;
}
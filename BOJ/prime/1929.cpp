#include <iostream>
#include <cmath>
using namespace std;

bool prime[1000001];
void eratos(int n) {
	for (int i = 2; i <= sqrt(n);i++) {
		if (!prime[i]) { //false이면 prime
			for (int j = i + i; j <= n; j += i) {
				prime[j] = true; //prime이 아님
			}
		}
	}
}
int main() {
	int m, n;
	cin >> m >> n;
	eratos(n);
	prime[1] = true;
	for (int i = m; i <= n; i++)
		if (!prime[i])
			cout << i << '\n';
}
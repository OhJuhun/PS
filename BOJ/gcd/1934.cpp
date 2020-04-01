#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    return b==0? a:gcd(b,a%b);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		int sum = a * b;
		int g = gcd(a, b);
		if (g != 0) sum /= g;
		cout << sum << '\n';
	}
}
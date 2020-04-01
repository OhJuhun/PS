#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	if (n == 0)
		cout << 0;
	else
	cout << n / 5 + n / 25 + n / 125;
	return 0;
}
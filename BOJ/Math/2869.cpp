#include <iostream>
#include <algorithm>
#include <vector>>
#include <map>
#include <string>
using namespace std;

int n, m;
vector<int> tw;
vector<int> sw;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long a, b, v;
	cin >> a >> b >> v;
	cout << (v - b - 1) / (a - b) + 1 << endl;
	return 0;
}
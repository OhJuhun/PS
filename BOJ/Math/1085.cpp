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
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int ans = min(w - x, x);
	int ans2 = min(h - y, y);
	cout << min(ans, ans2) << endl;
	return 0;
}
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int n;
		map<string, int> item;
		set<string> key;
		cin >> n;
		string name, it;
		for (int i = 0; i < n; i++) {
			cin >> name >> it;
			key.insert(it);
			item[it]++;
		}
		int ans = 1;
		for (auto i : key) {
			ans *= (item[i] + 1);
		}
		cout << ans - 1 << endl;
	}
	return 0;
}
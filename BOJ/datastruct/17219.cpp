#include <iostream>
#include <map>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	map<string, string> memo;
	while (n--) {
		string site, pw;
		cin >> site >> pw;
		memo[site] = pw;
	}
	while (m--) {
		string site;
		cin >> site;
		cout << memo[site] << '\n';
	}
	return 0;
}
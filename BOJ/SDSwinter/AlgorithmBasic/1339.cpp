#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	long long num[26] = { 0 };
	cin >> N;
	vector<string> v;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			num[str[j] - 'A'] += pow(10, str.length() - j-1);
		}
		v.push_back(str);
	}
	sort(num, num + 26);
	int x = 9;
	int ans = 0;
	for (int i = 25; i >= 0; i--) {
		ans += x-- * num[i];
	}
	cout << ans << endl;
    
    return 0;
}
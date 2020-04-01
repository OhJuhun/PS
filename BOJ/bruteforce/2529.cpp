#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	char c[10];
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 9; i >= 9 - n; i--) {
		v.push_back(i);
	}
	do {
		bool ans = true;
		for (int i = 0; i < v.size()-1; i++) {
			if (c[i] == '<') {
				if (v[i] > v[i + 1])
				{
					ans = false;
					break;
				}
			}
			else {
				if(c[i]=='>')
					if (v[i] < v[i + 1]) {
						ans = false;
						break;
					}
			}
		}
		if (ans)
			break;
	} while (prev_permutation(v.begin(), v.end()));
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << endl;
	v.clear();
	for (int i = 0; i < n + 1; i++)
		v.push_back(i);
	do {
		bool ans = true;
		for (int i = 0; i < v.size() - 1; i++) {
			if (c[i] == '<') {
				if (v[i] > v[i + 1])
				{
					ans = false;
					break;
				}
			}
			else {
				if (c[i] == '>')
					if (v[i] < v[i + 1]) {
						ans = false;
						break;
					}
			}
		}
		if (ans)
			break;
	} while (next_permutation(v.begin(), v.end()));
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	cout << endl;
	return 0;
}
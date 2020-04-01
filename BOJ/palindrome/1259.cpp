#include <iostream>
#include <algorithm>
#include <vector>>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while (true) {
		string str;
		cin >> str;
		if (str == "0") return 0;
		int j = str.length()-1;
		bool pal = true;
		for (int i = 0; i < str.length(); i++, j--)
			if (str[i] != str[j]) {
				pal = false;
				break;
			}
		if (pal)
			cout << "yes\n";
		else
			cout << "no\n";

	}
	return 0;
}
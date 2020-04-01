#include <iostream>
#include <algorithm>
#include <vector>>
#include <map>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	map<char, int> m;
	cin >> str;
	sort(str.begin(), str.end());
	char odd;
	for (int i = 0; i < str.length(); i++)
		m[str[i]] ++;
	str.erase(unique(str.begin(), str.end()), str.end());
	//중복 제거
	int odds = 0;
	for (char s : str)
		if (m[s] % 2 == 1) {
			odds++;
			odd = s;
		}
	if (odds >= 2) {
		cout << "I'm Sorry Hansoo\n";
		return 0;
	}
	string answer = "";
	if (odds == 1) {
		//홀수인 것이 한가지 일 때
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < m[str[i]] / 2; j++) {
				answer += str[i];
			}
		}
		answer += odd;
		for (int i = str.length() - 1; i >= 0; i--) {
			for (int j = 0; j < m[str[i]] / 2; j++) {
				answer += str[i];
			}
		}
	}
	else {
		for (int i = 0; i < str.length(); i++) {
			for (int j = 0; j < m[str[i]] / 2; j++) {
				answer += str[i];
			}
		}
		for (int i = str.length() - 1; i >= 0; i--) {
			for (int j = 0; j < m[str[i]] / 2; j++) {
				answer += str[i];
			}
		}
	}
	cout << answer << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <string>
using namespace std;


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;
	stack<char> s;
	queue<char> ans;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == '*' || str[i] == '/') {
			while (!s.empty() && (s.top() == '*' || s.top() == '/')) {
				ans.push(s.top());
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-') {
			while (!s.empty() && s.top() != '(') {
				ans.push(s.top());
				s.pop();
			}
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			while (!s.empty() && s.top() != '(') {
				ans.push(s.top());
				s.pop();
			}
			s.pop();
		}
		else
			ans.push(str[i]);
	}
	while (!ans.empty()) {
		cout << ans.front();
		ans.pop();
	}
	while (!s.empty()) {
		if(s.top()!='(')
			cout << s.top();
		s.pop();
	}
	return 0;
}
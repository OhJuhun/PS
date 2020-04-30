#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321


struct variable {
	string name;
	stack<char> giho;
};
int main() {
	PREPROCESS;
	string str;
	getline(cin,str);
	while (str != "") {
		string common = "";
		bool flag = false;
		vector<variable> v;
		variable var;
		for (int i = 0; i < str.length(); i++) {
			if (!flag && str[i] == ' ') {
				flag = true;
				var.name = " ";
				continue;
			}
			if (!flag) {
				common += str[i];
			}
			if (flag) {
				if (str[i] == ',' || str[i] == ';') {
					v.push_back(var);
					var.name = "";
					while (!var.giho.empty()) var.giho.pop();
					continue;
				}
				if ((str[i] >= 'a' && str[i] <= 'z') || (str[i]>='A' && str[i]<='Z'))
					var.name += str[i];
				else {
					var.giho.push(str[i]);
				}
			}
		}
		for (variable var2 : v) {
			cout << common;
			while (!var2.giho.empty()) {
				if (var2.giho.top() == ']') {
					cout << "[]";
					var2.giho.pop();
					var2.giho.pop();
					continue;
				}
				cout << var2.giho.top();
				var2.giho.pop();
			}
			cout << var2.name << ";\n";
		}
		getline(cin, str);
	}
	return 0;
}
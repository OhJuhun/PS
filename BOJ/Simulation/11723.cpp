#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	bool arr[21];
	while (n--) {
		string cmd;
		int v;

		cin >> cmd;
		if (cmd != "empty" && cmd != "all")
			cin >> v;
		if (cmd == "add") {
			arr[v] = 1;
		}
		else if (cmd == "remove") {
			arr[v] = 0;
		}
		else if (cmd == "check") {
			cout << arr[v] << '\n';
		}
		else if (cmd == "toggle") {
			arr[v] = !arr[v];
		}
		else if (cmd == "all") {
			for (int i = 1; i <= 20; i++)
				arr[i] = true;
		}
		else if (cmd == "empty") {
			for (int i = 1; i <= 20; i++)
				arr[i] = false;
		}
	}
	return 0;
}
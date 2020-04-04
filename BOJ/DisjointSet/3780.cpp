#include <iostream>
#include <cstring>
using namespace std;

#define MAX 987654321
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)

pair<int,int> parent[20001];

int Find(int x){
	if (parent[x].first == x) return x;
	int tmp = Find(parent[x].first);
	parent[x].second += parent[parent[x].first].second;
	parent[x].first = tmp;
	return tmp;
}

void Union(int a, int b) {
	parent[a].second = abs(a - b) % 1000;
	parent[a].first = b;
}
int main() {
	PREPROCESS;
	int T;
	cin >> T;
	while (T--) {

		int companies;
		cin >> companies;
		for (int i = 0; i <= companies; i++)
			parent[i].first = i, parent[i].second = 0;
		bool flag = true;
		while (flag) {
			char cmd;
			int i, j;
			cin >> cmd;
			switch (cmd) {
			case 'O':
				flag = false;
				break;
			case 'E':
				cin >> i;
				Find(i);
				cout << parent[i].second << '\n';
				break;
			case 'I':
				cin >> i >> j;
				Union(i, j);
				break;
			}
		}
	}
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;


int parent[1000001];
int Find(int a) {
	if (parent[a] == a) {
		return a;
	}
	else {
		int b = Find(parent[a]);
		parent[a] = b;
		return b;
	}
}
void unite(int a, int b) {
	a = Find(a);
	b = Find(b);
	parent[a] = b;
}


bool findParent(int a,int b){
	a = Find(a);
	b = Find(b);
	return a == b;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i; //parent 초기화
	}

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) { //union
			unite(b, c);
		}
		else { //find
			if (findParent(b, c)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}
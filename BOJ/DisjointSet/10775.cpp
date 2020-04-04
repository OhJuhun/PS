#include <iostream>
using namespace std;

#define MAX 987654321
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)

int G, P;
int g[100003];

int Find(int x) {
	return g[x]==x ? x : g[x] = Find(g[x]);
}
void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		g[x] = y;
	} 
}
int main() {
	PREPROCESS;
	cin >> G >> P;
	int ans = 0;
	for (int i = 1; i <= G; i++)
		g[i] = i;
	for (int i = 1; i <= P; i++) {
		int a;
		cin >> a;
		a = Find(a);
		if (a) {
			ans++;
			Union(a, a - 1);
		}
		else break;
	}
	cout << ans << endl;
	return 0;
}
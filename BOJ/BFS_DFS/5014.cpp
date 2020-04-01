#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int f, s, g, u, d; //u층 올라가거나 d 층 내려갈 수 있음
bool arr[1000001][2]; //1올라온 경우 0 내려간 경우
struct item {
	int s,ans;
};
int bfs() {
	item it = { s,0 };
	queue<item> q;
	q.push(it);
	while (!q.empty()) {
		item c = q.front();
		if (c.s == g) return c.ans;
		q.pop();
		item n;
		if (!arr[c.s + u][true] && c.s+u<=f) {
			//올라갈 수있는 경우
			arr[c.s + u][true] = true;
			n = { c.s + u,c.ans + 1 };
			q.push(n);
		}
		if (!arr[c.s - d][false] && c.s - d >= 1) {
			arr[c.s - d][false] = true;
			n = { c.s - d,c.ans + 1 };
			q.push(n);
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> f >> s >> g >> u >> d;
	int ans = bfs();
	if (ans == -1)
		cout << "use the stairs" << endl;
	else
		cout << ans << endl;
	return 0;
}
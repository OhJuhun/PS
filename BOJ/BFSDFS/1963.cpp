#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

bool prime[100001];
bool visit[10000];
int dir[8] = { 1000,-1000,100,-100,10,-10,1,-1 };
void eratos() {
	for (int i = 2; i <= 100; i++) {
		if (!prime[i])
			continue;
		for (int j = i + i; j <= 10000; j+=i) {
			prime[j] = false;
		}
	}
}
int main() {
	memset(prime, true, sizeof(prime));
	eratos();
	int x = 1033;
	int T;
	cin >> T;

	while (T--) {
		memset(visit, false, sizeof(visit));
		queue<int> q;
		queue<int> q2;
		q2.push(0);
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << 0 << '\n';
			continue;
		}
		q.push(a);
		visit[a] = true;
		bool flag = false;
		while (!q.empty()) {
			int cur = q.front();
			int curT = q2.front();
			q.pop();
			q2.pop();
			if (cur == b) {
				flag = true;
				cout << curT << "\n";
				break;
			}
			for (int i = 0; i < 8; i++) {
				//방향
				for (int j = 1; j <= 9; j++) {
					int next = cur + (dir[i] * j);
					if (i == 2 || i == 3) {
						if (cur / 1000 != next / 1000) continue;
					}
					else if (i == 4 || i == 5) {
						if (cur / 100 != next / 100) continue;
					}
					else if (i == 6 || i == 7) {
						if (cur / 10 != next / 10) continue;
					}
					if (next > 9999 || next < 1000) {
						continue;
					}
					if (!visit[next] && prime[next]) {
						visit[next] = true;
						q.push(next);
						q2.push(curT + 1);
					}
				}
			}
		}
		if (!flag) cout << "Impossible\n";
	}
	return 0;
}
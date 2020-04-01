#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;


bool visit[10001];
string bfs(int a, int b) {
	memset(visit, false, sizeof(visit));
	queue<pair<int, string>> q;
	q.push({ a,"" });
	//b가 타겟
	while (!q.empty()) {
		int cur = q.front().first;
		string answer = q.front().second;
		q.pop();
		if (cur == b) {
			return answer;
		}
		int next = cur * 2 %10000;
		if (!visit[next]) {
			//D
			visit[next] = true;
			q.push({ next,answer + "D" });
		}
		next = cur - 1 >= 0 ? cur - 1 : 9999;
		if (!visit[next]) {
			//S
			visit[next] = true;
			q.push({ next,answer + "S" });
		}
		next = (cur%1000)*10 + cur/1000;
		if (!visit[next]) {
			visit[next] = true;
			q.push({ next,answer + "L" });
		}
		next = (cur % 10) * 1000 + (cur / 10);
		if (!visit[next]) {
			visit[next] = true;
			q.push({ next,answer + "R" });
		}
	}
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	//n=((d1*10+d2)*10+d3)*10+d4
	int T;
	cin >> T;
	while (T--) {
		int a, b;
		cin >> a >> b; //초기값, 최종값
		cout << bfs(a, b) << '\n';
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

vector<int> v[32001];
int in[32001];

int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int a, b; //a가 bㅡ이 선행
		cin >> a >> b;
		in[b]++;
		v[a].push_back(b);
	}
	priority_queue<int, vector<int>, greater<int>> pq;
	queue<int> ans;
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			pq.push(i);
		}
	}
	while (!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		ans.push(cur);
		for (int next : v[cur]) {
			in[next]--;
			if (!in[next]) {
				pq.push(next);
			}
		}
	}
	while (!ans.empty()) {
		cout << ans.front() << " ";
		ans.pop();
	}
	return 0;
}
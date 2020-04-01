#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int main() {
	vector<int> v[32001];
	int cnt[32001] = { 0, };
	int N, M;
	int a, b;
	queue<int> q;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		cnt[b]++;
		v[a].push_back(b); // a가 b보다 작다
	} //a->b
	queue<int> ans;
	bool r = true;
	while (r) {
		r = false;
		for (int i = 1; i <= N; i++)
			if (cnt[i] == 0) {
				q.push(i);
				cnt[i] = -1;
				r=true;
			}
		if (r == 0) break;
		while (!q.empty()) {
			for (int i = 0; i < v[q.front()].size(); i++) {
				cnt[v[q.front()][i]]--;
			}
			ans.push(q.front());
			q.pop();
		}
	}
	
	while (!ans.empty()) {
		cout << ans.front() << " ";
		ans.pop();
	}
	cout << endl;
	
}
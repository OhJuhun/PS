#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;


int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	vector<int> v[1001];
	int in[1001];
	cin >> N >> M;
	//가수의 수, PD의 수
	for (int i = 1; i <= N; i++) {
		in[i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b;
		for (int j = 1; j < a; j++) {
			cin >> c;
			v[b].push_back(c);
			in[c]++;
			b = c;
		}
	}
	queue<int> q;
	queue<int> ans;
	for (int i = 1; i <= N; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		ans.push(cur);
		for (int next : v[cur]) {
			in[next]--;
			if (in[next] == 0) {
				q.push(next);
			}
		}
	}
    if(ans.size()!=N){
        cout<<0<<'\n';
        return 0;
    }
	while (!ans.empty()) {
		cout << ans.front() << '\n';
		ans.pop();
	}
	return 0;
}
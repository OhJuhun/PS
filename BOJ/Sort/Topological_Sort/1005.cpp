#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;



int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	vector<int> answers;
	while (T--) {
		int N, K, W;
		int delay[1001];
		int order[1001];
		bool check[1001];
		vector<int> v[1001]; //i->j
		int answer[1001];
		cin >> N >> K;
		order[0] = 0;
		check[0] = false;
		answer[0] = 0;
		for (int i = 0; i < N; i++) {
			cin >> delay[i + 1];
			order[i + 1] = 0;
			answer[i + 1] = 0;
			check[i + 1] = true;
		}
		for (int i = 0; i < K; i++) {
			int X, Y;
			cin >> X >> Y;
			v[X].push_back(Y);
			order[Y]++; //Y이전에 선행되어야할 work의 갯수 증가
		}
		cin >> W;
		queue<int> q;
		for (int i = 1; i <= N; i++) {
			//차수가 0인 애들을 찾는아서 넣는다
			if (check[i] && order[i] == 0) {
				q.push(i);
				check[i] = false;
				answer[i] = delay[i];
			}
		}
		while (!q.empty()) {
			int cur = q.front();
			if (cur == W) break;
			q.pop();
			for (int i : v[cur]) {
				order[i]--;
				if (order[i] == 0 && check[i]) {
					q.push(i);
					check[i] = false;
				}
				if (answer[i] < answer[cur] + delay[i])
					answer[i] = answer[cur] + delay[i];

			}
			
		}
		cout << answer[W] << '\n';

	}
	return 0;
}
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

	int N;
	cin >> N;
	int delay[501];
	int order[501];
	int answer[501];
	for (int i = 1; i <= N; i++) {
		order[i] = 0;
		delay[i] = 0;
	}
	vector<int> child[501];
	for (int i = 1; i <= N; i++) {
		while (true) {
			int time;
			cin >> time;
			if (time == -1) break;
			if (delay[i] == 0) {
				//딜레이가 설정되지 않았으면 설정
				delay[i] = time;
			}
			else {
				//딜레이가 설정되어 있다면 다 자식
				child[time].push_back(i);
				order[i]++; //차수 증가
			}
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (order[i] == 0) {
			q.push(i);
			answer[i] = delay[i];
		}
	} //초기 상태 설정

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int next : child[cur]){
			order[next]--;
			if (order[next] == 0) {
				q.push(next);
			}
			if (answer[next] < answer[cur] + delay[next])
				answer[next] = answer[cur] + delay[next];
		}
	}

	for (int i =1; i<=N; i++)
		cout << answer[i] << '\n';
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int N, M;
int arr[1001][1001];
bool visit[1001];

void bfs(int n){
	visit[n] = true;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (!visit[i] && arr[c][i]==1) {
				q.push(i);
				visit[i] = true;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		arr[u][v] = 1;
		arr[v][u] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!visit[i]) bfs(i), ans++;
	}
	cout << ans << endl;
}
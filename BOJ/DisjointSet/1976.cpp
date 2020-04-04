#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define MAX 987654321
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)

int N, M;
int arr[201][201];
int parent[201];
bool visit[201];
int Find(int x) {
	return !parent[x] ? x : 
		parent[x] = Find(parent[x]);
}
void Union(int a, int b) {
	int x = Find(a);
	int y = Find(b);

	if (x != y) {
		parent[y] = x;
	}
}
int main() {
	PREPROCESS;
	cin >> N >> M;
	memset(parent, 0, sizeof(parent));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin>>arr[i][j];
			if (arr[i][j]) {
				Union(i, j);
			}
		}
	}
	queue<int> pq;

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		pq.push(a);
	}
	int bef = Find(pq.front());
	pq.pop();
	while (!pq.empty()) {
		int cur = Find(pq.front());
		if (cur != bef) break;
		pq.pop();
	}
	cout << (pq.empty() ? "YES" : "NO") << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

int r, c, k;

int arr[102][102];

int n = 3, m = 3;
void R() {
	//행에 대한 정렬 행의 수 >=열의 수
	int nn = n;
	int mm = m;
	queue<int> rSize;
	for (int i = 1; i <= nn; i++) {
		//모든 행에 대해
		map<int, int> tmp;
		queue<int> q;

		for (int j = 1; j <= mm; j++) {
			if (arr[i][j] == 0) continue;
			tmp[arr[i][j]]++;
			q.push(arr[i][j]);
		}
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		while (!q.empty()) {
			if (tmp[q.front()] == 0) {
				q.pop();
				continue;
			}
			pq.push({ tmp[q.front()],q.front() });
			tmp[q.front()] = 0;
			q.pop();
		}
		int j = 1;
		while (!pq.empty()) {
			arr[i][j++] = pq.top().second;
			arr[i][j++] = pq.top().first;
			pq.pop();
			if (j > 100) break;
		}
		m = max(j - 1, m);
		rSize.push(j - 1);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (rSize.front() < j)
				arr[i][j] = 0;
		}
		rSize.pop();
	}
}
void C() {
	//열에 대한 정렬 열의 수 >행의 수
	int nn = n;
	int mm = m;
	queue<int> rSize;
	for (int j = 1; j <= mm; j++) {

		map<int, int> tmp;
		queue<int> q;
		for (int i = 1; i <= nn; i++) {
			if (arr[i][j] == 0) continue;
			tmp[arr[i][j]]++;
			q.push(arr[i][j]);
		}
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		while (!q.empty()) {
			if (tmp[q.front()] == 0) {
				q.pop();
				continue;
			}
			pq.push({ tmp[q.front()],q.front() });
			tmp[q.front()] = 0;
			q.pop();
		}
		int i = 1;
		while (!pq.empty()) {
			arr[i++][j] = pq.top().second;
			arr[i++][j] = pq.top().first;
			if (i > 100) break;
			pq.pop();
		}
		n = max(i - 1, n);
		rSize.push(i - 1);
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (rSize.front() < i)
				arr[i][j] = 0;
		}
		rSize.pop();
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> r >> c >> k; //A[r][c]에 k가 되기 위한 최소 시간
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++)
			cin >> arr[i][j];
	}
	//arr[r][c]=k일때까지
	int ans = 0;
	while (arr[r][c] != k) {
		if (n >= m)
			R();
		else
			C();
		if (ans > 100) break;
		ans++;
	}
	ans = ans > 100 ? -1 : ans;
	cout << ans << endl;
	return 0;
}
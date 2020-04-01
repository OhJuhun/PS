#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 987654321
struct item {
	int r, c, t;
};
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
int N, M;
int arr[51][51];
int copied[51][51];
vector<pair<int,int>> cand;
vector<int> toggle;

void copy() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			copied[i][j] = arr[i][j];
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int full = N * N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) full--;
			if (arr[i][j] == 2) {
				cand.push_back({ i,j }); //후보군
				arr[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < M; i++)
		toggle.push_back(1);
	for (int i = M; i < cand.size(); i++)
		toggle.push_back(0);
	int ans = MAX;
	do
	{
		queue<item> q;
		copy();
		for (int i = 0; i < cand.size(); i++) {
			if (toggle[i]) {
				q.push({ cand[i].first,cand[i].second,0 });
				copied[cand[i].first][cand[i].second] = 9;
			}
		}
		int localans;
		int viruses = 0;
		while (!q.empty()) {
			item cur = q.front();
			q.pop();
			localans = cur.t;
			viruses++;
			for (int i = 0; i < 4; i++) {
				item next = { cur.r + dir[i][0],cur.c + dir[i][1],cur.t + 1 };
				if (next.r > N || next.c > N || next.r < 1 || next.c < 1 || copied[next.r][next.c])
					continue;
				copied[next.r][next.c] = next.t;
				q.push(next);
			}
		}
		if(viruses==full)
			ans = min(localans, ans);
	} while (prev_permutation(toggle.begin(), toggle.end()));


	cout <<( ans!=MAX ? ans : -1)<< endl;
	return 0;
}
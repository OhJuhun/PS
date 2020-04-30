#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321


struct item {
	int r, c;
};
int N, M, G, R;
int arr[51][51];
int tmparr[51][51];
vector<pair<int, int>> v;
vector<int> land; //0의 수가 v.size()-(R+G)
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void cpy() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			tmparr[i][j] = arr[i][j];
	}
}

int bfs() {
	queue<item> gq;
	queue<item> rq;
	bool visit[51][51];
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < land.size(); i++) {
		item tmp;
		if (land[i] == 1) {
			//G
			tmp.r = v[i].first;
			tmp.c = v[i].second;
			tmparr[tmp.r][tmp.c] = -1;
			visit[tmp.r][tmp.c] = true;
			gq.push(tmp);
		}
		else if (land[i] == 2) {
			//R
			tmp.r = v[i].first;
			tmp.c = v[i].second;
			tmparr[tmp.r][tmp.c] = -1;
			visit[tmp.r][tmp.c] = true;
			rq.push(tmp);
		}
	}
	int ret = 0;
	while (!rq.empty() || !gq.empty()) {
		int gqsize = gq.size();
		while (gqsize--) {
			item cur = gq.front();
			gq.pop();
			if (tmparr[cur.r][cur.c] == 9) continue;
			for (int i = 0; i < 4; i++) {
				item next = cur;
				next.r += dir[i][0];
				next.c += dir[i][1];
				if (!(tmparr[next.r][next.c] == 1 || tmparr[next.r][next.c] == 2) || next.r > N || next.c > M || next.r < 1 || next.c < 1) continue;
				tmparr[next.r][next.c] = 5;
				gq.push(next);
			}
			tmparr[cur.r][cur.c] = -1; //이제 더이상 퍼지지 않는 배양액
		}
		int rqsize = rq.size();
		while (rqsize--) {
			item cur = rq.front();
			rq.pop();
			for (int i = 0; i < 4; i++) {
				item next = cur;
				next.r += dir[i][0];
				next.c += dir[i][1];
				if (tmparr[next.r][next.c] == 5) {
					//5라면 같이 퍼진것임
					tmparr[next.r][next.c] = 9; //flower
					ret++;
					continue;
				}
				if (!(tmparr[next.r][next.c] == 1 || tmparr[next.r][next.c] == 2) || next.r > N || next.c > M || next.r < 1 || next.c < 1) continue;
				tmparr[next.r][next.c] = -1; //죽은 배양액
				rq.push(next);
			}
			tmparr[cur.r][cur.c] = 0;
		}
		
	}
	
	return ret;
}
int solve() {
	for (int i = 0; i < v.size() - (R + G); i++) {
		land.push_back(0);
	}
	for (int i = 0; i < G; i++)
		land.push_back(1);
	for (int i = 0; i < R; i++)
		land.push_back(2);
	int ans = 0;
	do {
		cpy();
		ans=max(ans,bfs());
	} while (next_permutation(land.begin(), land.end()));

	return ans;
}
void input() {
	cin >> N >> M >> G >> R;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) v.push_back(make_pair(i, j)); //배양액을 뿌릴 수 있는 땅만 모음
		}
	}
}
int main() {
	PREPROCESS;
	input();
	cout << solve() << endl;
	return 0;
}
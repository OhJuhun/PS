#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[21][21];
pair<int, int> shark;
int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
bool visit[21][21];
int ate;
int level = 2;
int answer = 0;
struct item {
	int r, c, len;
};

bool bfs() {
	queue<item> q;
	memset(visit, false, sizeof(visit));
	visit[shark.first][shark.second] = true;
	q.push({ shark.first,shark.second,0 });
	int tc, tr, tlen=0;
	while (!q.empty()) {
		item cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			item next = { cur.r + dir[i][0], cur.c + dir[i][1],cur.len + 1 };
			if (next.len > tlen && tlen != 0) break;
			if (next.r < 0 || next.c < 0 || 
				next.c >= n || next.r >= n ||
				visit[next.r][next.c]) {
				continue; //범위를 벗어난 경우
			}
			if (arr[next.r][next.c] <= level) {
				//방문이 가능한 경우
				q.push(next);
				visit[next.r][next.c] = true; //방문할 위치 visit 정보 초기화
				if (arr[next.r][next.c] == level || arr[next.r][next.c]==0) continue;
				
				//먹을 수 있는 경우
				if (!tlen) {
					//먹을 수 있는 첫번째 경우일 때
					tc = next.c, tr = next.r, tlen = next.len;
				}
				else {
					if (next.len > tlen) continue;
					//방문할 곳이 현재 최소 len보다 짧은 경우 
					else if (next.len == tlen) {
						if (tr == next.r) {
							//높이가 같은 경우는 왼쪽 우선
							if (next.c < tc) {
								//더 왼쪽에 있는 경우 변경해줌
								tc = next.c;
							}
						}
						else if (next.r < tr) {
							//다음 방문할 곳이 더 위에 있는 경우
							tr = next.r, tc = next.c;
						}
					}
					else {
						tr = next.r, tc = next.c, tlen = next.len;
					}
				}
				
			}
		}
	}
	if (tlen) {
		//먹을 수 있는 곳을 발견했을 경우
		arr[tr][tc] = 9;
		arr[shark.first][shark.second] = 0;
		shark.first = tr, shark.second = tc;
		ate++;
		answer += tlen;
		if (ate == level) ate = 0, level++;
	}
	return tlen == 0 ? false : true;
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9)
				shark = { i,j };
		}
	}
	
	while (bfs());
	cout << answer << endl;
	return 0;
}
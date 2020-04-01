#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
char arr[51][51];
int godo[51][51];
bool visit[51][51];
pair<int, int> park;
vector<int> godos;
int dir[8][2] = { {1,0},{1,1},{0,1},{-1,0},{-1,-1},{0,-1},{1,-1},{-1,1} };

int main() {
	cin >> N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'P') park = { i,j };
			else if (arr[i][j] == 'K') cnt++;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> godo[i][j];
			godos.push_back(godo[i][j]);
		}
	}

	sort(godos.begin(), godos.end());
	godos.erase(unique(godos.begin(), godos.end()),godos.end());
	//최소 피로도
	int l = 0, h = 0;
	int answer = 987654321;
	while (l < godos.size()) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				visit[i][j] = false;
		}
		queue < pair<int, int>> q;
		int g = godo[park.first][park.second];
		if (g >= godos[l] && g <= godos[h]) {
			visit[park.first][park.second] = true;
			q.push(park);
		}
		int r = 0;
		while (!q.empty()) {
			pair<int, int> c = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				pair<int, int> n = { c.first + dir[i][0],c.second + dir[i][1] };
				if (!visit[n.first][n.second] && n.first >= 0 && n.second >= 0 && n.first < N && n.second < N) {
					//추가 가능한 경우
					g = godo[n.first][n.second];
				//	cout << g << " " << godos[l] << " " << godos[h] << endl;
					if (g >= godos[l] && g <= godos[h]) {
						visit[n.first][n.second] = true;
						q.push(n);
						if (arr[n.first][n.second] == 'K') r++;
					}
				}
			}
		}
		if (r == cnt) {
			answer = min(answer, godos[h] - godos[l]);
			l++;
		}
		else if (h + 1 < godos.size()) {
			h++;
		}
		else {
			break;
		}
	}
	cout << answer << endl;
	return 0;
}

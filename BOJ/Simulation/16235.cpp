#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

struct tree {
	int r, c, age;
	bool die = false;
};

int N, M, K;
vector<int> v[11][11];
int land[11][11];
int arr[11][11];
int dir[8][2] = { {0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1} };

void ss() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			sort(v[i][j].begin(), v[i][j].end());
			bool flag = false;
			vector<int> dead;
			for (int k = 0; k < v[i][j].size(); k++) {
				if (!flag) {
					if (v[i][j][k] <= land[i][j]) {
						land[i][j] -= v[i][j][k];
						v[i][j][k]++;
					}
					else {
						flag = true;
					}
				}
				if (flag) {
					dead.push_back(v[i][j][k]); //죽은 나무의 나이
				//	v[i][j][k] = MAX;
				}
			}
			for (int k = 0; k < dead.size(); k++) {
				v[i][j].pop_back(); //죽은 나무 소멸
				land[i][j] += dead[k] / 2;
			} //여름
		}
	}
}
void fw() { //살아있는 나무의 번식
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (v[i][j].empty()) continue;
			int tsize = v[i][j].size();
			for (int k = 0; k < tsize; k++) {
				if (v[i][j][k] % 5 != 0) continue;
				for (int d = 0; d < 8; d++) {
					int dr = i + dir[d][0];
					int dc = j + dir[d][1];
					if (dr > N || dc > N || dr < 1 || dc < 1) continue;
					v[dr][dc].push_back(1);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			land[i][j] += arr[i][j];
	}
}

int getAns() {
	int ret = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			ret += v[i][j].size();
	}
	return ret;
}
int solve() {
	while (K--) {
		ss();
		fw();
	}
	return getAns();
}
void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			land[i][j] = 5; //초기에는 5로 셋돼있음
		}
	}
	for (int i = 0; i < M; i++) {
		int r, c, a;
		cin >> r >> c >> a;
		v[r][c].push_back(a);
	}
}
int main() {
	PREPROCESS;
	input();
	cout << solve() << '\n';
	return 0;
}
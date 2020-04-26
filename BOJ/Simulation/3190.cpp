#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int N, K, L;
int arr[101][101];
queue<pair<int, char>> q; //first초에 second로 방향 변경
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
deque < pair<int, int>> info;
int dinfo = 3;

void cd(char c) {
	if (c == 'L') {
		switch (dinfo) {
		case 0:
			dinfo = 3;
			break;
		case 1:
			dinfo = 2;
			break;
		case 2:
			dinfo = 0;
			break;
		case 3:
			dinfo = 1;
			break;
		}
	}
	else if (c == 'D') {
		switch (dinfo) {
		case 0:
			dinfo = 2;
			break;
		case 1:
			dinfo = 3;
			break;
		case 2:
			dinfo = 1;
			break;
		case 3:
			dinfo = 0;
			break;
		}
	}
}
int solve() {
	int sec = 0;
	info.push_back(make_pair(1, 1)); //꼬리이자 머리
	while (true) {
		if (!q.empty() && q.front().first == sec) {
			cd(q.front().second);
			q.pop();
		} //방향 변경정보
		pair<int, int> next = info[info.size() - 1];
		next.first += dir[dinfo][0];
		next.second += dir[dinfo][1]; //다음 head의 위치
		if (next.first<1 || next.second<1 || next.first>N || next.second>N || arr[next.first][next.second] == 1) break;
		//범위를 벗어나거나 자신과 만나는 경우
		if (arr[next.first][next.second] == 0) {
			arr[info[0].first][info[0].second] = 0;
			info.pop_front(); //사과가 없으면 꼬리를 자른다
		}
		arr[next.first][next.second] = 1;
		info.push_back(next);
		

		sec++;
	}

	return 1+sec;
}
void input() {
	cin >> N >> K;
	arr[1][1] = 1; //bam
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		arr[r][c] = 2;//사과
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int n;
		char d;
		cin >> n >> d;
		q.push(make_pair(n, d));
	}
}
int main() {
	PREPROCESS;
	input();
	cout<<solve()<<'\n';
	return 0;
}
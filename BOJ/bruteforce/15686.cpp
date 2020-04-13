#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int N, M;
int arr[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
bool valid[13];
int answer = MAX;
void distance() {
	//치킨거리는 abs(x1-x2) + abs(y1-y2)
	int city = 0;
	for (int i = 0; i < house.size(); i++) {
		int home = MAX;//i에서 j까지 치킨 거리
		for (int j = 0; j < chicken.size(); j++) {
			if (!valid[j]) continue; //가능한 곳일 경우에만
			home = min(home, (abs(chicken[j].first - house[i].first) +
				abs(chicken[j].second - house[i].second)));
		}
		city += home;
	}
	answer = min(city, answer);
}
void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) chicken.push_back(make_pair(i, j));
			else if (arr[i][j] == 1) house.push_back(make_pair(i, j));
		}
	}
}
int main() {
	PREPROCESS;

	input();
//	memset(valid, true, sizeof(valid));//처음에는 모든 치킨집 사용 가능
//	distance();
	memset(valid, false, sizeof(valid));
	for (int i = 0; i < M; i++) {
		valid[i] = true;
	}
	do {
		distance();
	}while(prev_permutation(valid, valid + chicken.size()));
	cout << answer << endl;
	return 0;
}
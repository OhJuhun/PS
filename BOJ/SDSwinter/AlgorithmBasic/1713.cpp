#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstdio>

using namespace std;

int pictures[21]; //사진틀
int chu[101]; //추천수
int N, M;
int idx = 0;


void modify(int x) {
	int minIdx = 0;
	for (int i = 1; i < idx; i++) {
		if (chu[pictures[minIdx]] > chu[pictures[i]]) {//가장 앞에 있는 최솟값을 찾는다
			minIdx = i;
		}
	}
	chu[pictures[minIdx]] = 0; //가장 추천을 적게 받은 놈을 0으로
	for (int i = minIdx; i < idx - 1; i++) {
		//앞으로 한 칸씩 미뤄서 오래되었다는 것을 표기
		pictures[i] = pictures[i + 1];
	}
	pictures[idx - 1] = x;
	chu[x]++;
}
void search(int x) {
	for (int i = 0; i < idx; i++) {
		if (pictures[i] == x) { //x의 사진이 걸려있는 경우
			chu[x]++;
			return;
		}
	}
	//안걸려있는 경우
	if (idx == N) { //꽉찼을 때
		modify(x);
	}
	else {//안 꽉찼을때
		chu[x]++;
		pictures[idx++] = x;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> M;
	while (M--) {
		int x;
		cin >> x;
		//x가 추천받음
		search(x);
	}
	sort(pictures, pictures + idx);
	for (int i = 0; i < idx; i++)
		cout << pictures[i] << " ";
	cout << '\n';
}

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 98765432
//접수처 수 정비소 수 사람수 A->B를 이용했다
int N, M, K, A, B;
int a[10]; //i번을 이용하는데 걸리는 시간
pair<int, int> useA[10]; //A사용정보
pair<int, int> useB[10];
int b[10]; //i번을 이용하는데 걸리는 시간
int t[1001]; //i번 사람의 도착 시간
queue<int> readya; //선입 선출
queue<int> readyb;
pair<int, int> useinfo[1001];

void fillreadya(int time) {
	for (int i = 1;i <= K; i++) {
		if (t[i] <= time && t[i]!=-1) {
			t[i] = -1;
			readya.push(i); //i번째 사람을 대기열에 넣음
		}

	}
}
void seta() {
	for (int i = 1; i <= N; i++) {
		if (readya.empty()) break; //대기중인 사람이 없으면 종료
		if (useA[i].first == 0 && useA[i].second == 0) {
			//i번 A에 사람이 없는 경우
			useA[i].first = readya.front();
			useA[i].second = a[i]; //first : 현재 들어가 있는 사람 second :남은 시간
			useinfo[useA[i].first].first = i; //사용한 A번호
			readya.pop();
		}
	}
}

void usingA() {
	for (int i = 1; i <= N; i++) {

		if (useA[i].first != 0) {
			//A[i]를 사용중인 사람이 있는 경우
			useA[i].second--;
			//시간 감소
		}
		if (useA[i].second == 0 && useA[i].first != 0) {
			readyb.push(useA[i].first); //B의 대기 큐에 넣음
			useA[i].first = 0;
		}
	}
}

void setB() {
	for (int i = 1; i <= M; i++) {
		if(readyb.empty()) break; //b를 기다리는 사람이 없는 경우
		if (useB[i].first == 0 && useB[i].second == 0) {
			//b[i]를 사용중인 사람이 없으면
			useB[i].first = readyb.front();
			useB[i].second = b[i];
			useinfo[useB[i].first].second = i; //얘는 B[i]를 사용했음
			readyb.pop();
		}
	}
}
void usingB() {
	for (int i = 1; i <=M; i++) {

		if (useB[i].first != 0) {
			useB[i].second--;
		}
		if (useB[i].second == 0 && useB[i].first != 0) {
			useB[i].first = 0;
		}
	}
}

bool check() {
	for (int i = 1; i <= K; i++) {
		if (useinfo[i].first == 0 || useinfo[i].second == 0) return false;
	}
	return true;
}


int getAns() {
	int ans = 0;
	for (int i = 1; i <= K; i++) {
		if (useinfo[i].first == A && useinfo[i].second == B) ans += i;
	}
	return ans ? ans : -1;
}
void solve() {
	int time = 0;
	while (true) {
		fillreadya(time++);
		seta();
		usingA();
		setB();
		usingB();
		if (check()) break;
	}
}
void input() {

	cin >> N >> M >> K >> A >> B;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(useA, 0, sizeof(useA));
	memset(useB, 0, sizeof(useB));
	memset(t, 0, sizeof(t));
	memset(useinfo, 0, sizeof(useinfo));
	while (!readya.empty()) readya.pop();
	while (!readyb.empty()) readyb.pop();
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	for (int i = 1; i <= M; i++)
		cin >> b[i];
	for (int i = 1; i <= K; i++)
		cin >> t[i];
}
int main() {
	PREPROCESS;

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		input();
		solve();
		cout <<"#"<<t<<" "<< getAns() << '\n';
	}
	return 0;
}
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321

int arr[33][6] = {
{0,1,2,3,4,5}, // 0
{2,2,3,4,5,6}, // 1
{4,3,4,5,6,7}, // 2
{6,4,5,6,7,8}, // 3
{8,5,6,7,8,9}, // 4
{10,21,22,23,24,25}, //여기를 채워야함5
{12,7,8,9,10,11}, // 6 
{14,8,9,10,11,12}, //7
{16,9,10,11,12,13},  // 8
{18,10,11,12,13,14},//9
{20,26,27,24,25,28}, //여기도 채워야함10
{22,12,13,14,15,16}, //11
{24,13,14,15,16,17},//12
{26,14,15,16,17,18},//13
{28,15,16,17,18,19},//14
{30,29,30,31,24,25}, //여기도 채워야함 15
{32,17,18,19,20,32}, //16
{34,18,19,20,32,32}, //17
{36,19,20,32,32,32}, //18
{38,20,32,32,32,32}, //19
{40,32,32,32,32,32}, //20
{13,22,23,24,25,28}, //21
{16,23,24,25,28,20}, //22
{19,24,25,28,20,32}, //23
{25,25,28,20,32,32}, //24
{30,28,20,32,32,32},//25
{22,27,24,25,28,20},//26
{24,24,25,28,20,32},//27
{35,20,32,32,32,32},//28
{28,30,31,24,25,28}, //29
{27,31,24,25,28,20},//30
{26,24,25,28,20,32},//31
{0,32,32,32,32,32}//32
};
int dice[10];
int curh[10];
int horse[4]; // 4개의 말의 위치. 처음에는 0임
int ans = 0; //최종 결과
void answer(int n) {
	
	if (n == 10) {
		int tmpans = 0;
		memset(horse, 0, sizeof(horse));
		for (int i = 0; i < 10; i++) {
			int h = curh[i]; //현재 고른 말 번호
			int p = horse[h]; //현재 고른 말의 위치
			p = arr[p][dice[i]]; //이번 이동 후 말의 위치 
			for (int j = 0; j < 4; j++) {
				if (horse[j] == p && p!=32) return; //이미 해당 위치에 다른 말이 있는 경우는 이동 불가
			}

			horse[h] = p; //현재 말의 위치 이동
			tmpans += arr[p][0]; //점수 증가
		}
		ans = max(ans, tmpans);
		return;
	}
	for (int i = 0; i < 4; i++) {
		curh[n] = i;
		answer(n + 1);
	}
}
void input() {
	for (int i = 0; i < 10; i++)
		cin >> dice[i];
}
int main() {
	PREPROCESS;
	input();
	answer(0);
	cout << ans << endl;

}
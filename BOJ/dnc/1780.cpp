#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cmath>
using namespace std;

int arr[3000][3000];
bool flag[3000][3000];
int m = 0, p = 0, z = 0;

void answer(int sr, int sc, int size) {

	bool f = true;
	int bef = arr[sr][sc];
	for (int i = sr; i < sr+size; i++) {
		for (int j = sc; j <sc+size; j++) {
			if (bef != arr[i][j]) {
				f = false;
			}
		}
	}
	if (f) {
		if (bef == 0)
			z++;
		else if (bef > 0)
			p++;
		else
			m++;
	}
	else {
		//9등분하기
		answer(sr, sc, size / 3);
		answer(sr + 1*size/3, sc, size / 3);
		answer(sr + 2 * size/3, sc, size / 3);
		answer(sr, sc + 1 * size/3, size / 3);
		answer(sr, sc + 2 * size/3, size / 3);
		answer(sr + 1 * size/3, sc + 1 * size/3, size / 3);
		answer(sr + 2 * size/3, sc + 1 * size/3, size / 3);
		answer(sr + 1 * size/3, sc + 2 * size/3, size / 3);
		answer(sr + 2 * size/3, sc + 2 * size/3, size / 3);
	}
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	for (int i =0; i < n; i++) {
		for (int j = 0; j <n; j++)
			cin >> arr[i][j];
	}
	answer(0, 0, n);
	cout << m << '\n' << z<< '\n' <<p << '\n';
	return 0;
}
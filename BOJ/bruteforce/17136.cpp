#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

bool arr[12][12];
vector<pair<int, int>> v;
int ans = 26;

int findNext(int n) {
	
	for (int i = n; i < v.size(); i++) {
		if (arr[v[i].first][v[i].second])
			return i;
	}
	return 101;
}
void answer(int one,int two,int three,int four, int five,int n) {

	if (one > 5 || two > 5 || three > 5 || four > 5 || five > 5) return; //불가능한 경우
	if (n >= v.size()) {
		int tmp = one + two + three + four + five;
		if (tmp < ans) ans = tmp;
		return; 
	}//마지막일 경우 끝
	int i = v[n].first;
	int j = v[n].second;
	
	bool flag = true;
	for (int ii = 0; ii < 5; ii++) {
		for (int jj = 0; jj < 5; jj++) {
			if (!arr[i + ii][j + jj]) {
				flag = false;
			}
		}
	}
	if (flag) {
		for (int ii = 0; ii < 5; ii++) {
			for (int jj = 0; jj < 5; jj++) {
				arr[i + ii][j + jj] = false;
			}
		}
		answer(one, two, three, four, five + 1, findNext(n));
		for (int ii = 0; ii < 5; ii++) {
			for (int jj = 0; jj < 5; jj++)
				arr[i + ii][j + jj] = true;
		}
	}

	flag = true;
	for (int ii = 0; ii < 4; ii++) {
		for (int jj = 0; jj < 4; jj++) {
			if (!arr[i + ii][j + jj]) {
				flag = false;
			}
		}
	}
	if (flag) {
		for (int ii = 0; ii < 4; ii++) {
			for (int jj = 0; jj < 4; jj++) {
				arr[i + ii][j + jj] = false;
			}
		}
		answer(one, two, three, four + 1, five, findNext(n));
		for (int ii = 0; ii < 4; ii++) {
			for (int jj = 0; jj < 4; jj++)
				arr[i + ii][j + jj] = true;
		}
	}

	
	flag = true;
	for (int ii = 0; ii < 3; ii++) {
		for (int jj = 0; jj < 3; jj++) {
			if (!arr[i + ii][j + jj]) {
				flag = false;
			}
		}
	}

	if (flag) {
		for (int ii = 0; ii < 3; ii++) {
			for (int jj = 0; jj < 3; jj++) {
				arr[i + ii][j + jj] = false;
			}
		}
		answer(one, two, three + 1, four, five, findNext(n));
		for (int ii = 0; ii < 3; ii++) {
			for (int jj = 0; jj < 3; jj++)
				arr[i + ii][j + jj] = true;
		}
	}

	flag = true;
	for (int ii = 0; ii < 2; ii++) {
		for (int jj = 0; jj < 2; jj++) {
			if (!arr[i + ii][j + jj]) {
				flag = false;
			}
		}
	}
	if (flag) {
		for (int ii = 0; ii < 2; ii++) {
			for (int jj = 0; jj < 2; jj++) {
				arr[i + ii][j + jj] = false;
			}
		}
		answer(one, two + 1, three, four, five, findNext(n));
		for (int ii = 0; ii < 2; ii++) {
			for (int jj = 0; jj < 2; jj++)
				arr[i + ii][j + jj] = true;
		}
	}

	if (arr[i][j]) {
		arr[i][j] = false;
		answer(one + 1, two, three, four, five, findNext(n));
		arr[i][j] = true;
	} //한개짜리

}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> arr[i][j];
			if(arr[i][j])
				v.push_back({ i, j });
		}
	}
	
	answer(0, 0, 0, 0, 0, 0);
	if (ans == 26) cout << -1 << '\n';
	else
		cout << ans << endl;

	

	return 0;
}
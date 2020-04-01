#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int arr[501][501];
int answer = 0;

/*
aa
aa
*/
void rectangle() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//i,j에서 시작한다
			if (i + 1 >= n || j + 1 >= m) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
			answer = max(tmpans, answer);
		}
	}
}
/*
aaaa
*/
void spacebar() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 3 >= m) continue;
			int tmpans = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
			answer = max(tmpans, answer);
		}
	}
}
/*
a
a
a
a
*/
void spacebar2() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 3 >= n) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
			answer = max(tmpans, answer);
		}
	}
}
/*
a
a
aa
*/
void shape3() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 2 >= n || j + 1 >= m) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j+1];
			answer = max(tmpans, answer);
		}
	}
}
/*
aa
a
a
*/
void shape3a() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 >= n || j + 2 >= m) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i][j + 2];
			answer = max(tmpans, answer);
		}
	}
}
/*
aa
 a
 a
*/
void shape3b() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 2 >= n || j + 1 >= m) continue;
			int tmpans = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			answer = max(tmpans, answer);
		}
	}
}
/*
  a
aaa
*/
void shape3c() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i - 1 < 0 || j + 2 >= m) continue;
			int tmpans = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 2];
			answer = max(tmpans, answer);
		}
	}
}
/*
 a
 a
aa
*/
void shape3t() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j - 1 < 0 || i + 2 >= n) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j - 1];
			answer = max(tmpans, answer);
		}
	}
}

void shape3ta() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 >= n || j + 2 >= m) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 2] + arr[i + 1][j + 1];
			answer = max(tmpans, answer);
		}
	}
}

void shape3tb() {
	for (int i = 0; i < n; i++) {
		for (int j = 0;j < m; j++) {
			if (i + 2 >= n || j + 1 >= m) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i][j + 1];
			answer = max(tmpans, answer);
		}
	}
}

void shape3tc() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 >= n || j + 2 >= m) continue;
			int tmpans = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
			answer = max(tmpans, answer);
		}
	}
}

void shape4() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 2 >= n || j + 1 >= m) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			answer = max(tmpans, answer);
		}
	}
}

void shape4a() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i - 1 < 0 || j + 2 >= m) continue;
			int tmpans = arr[i][j] + arr[i][j + 1] + arr[i - 1][j + 1] + arr[i - 1][j + 2];
			answer = max(tmpans, answer);
		}
	}
}

void shape4t() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 2 >= n || j - 1 < 0) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i + 1][j - 1] + arr[i + 2][j - 1];
			answer = max(tmpans, answer);
		}
	}
}
void shape4ta() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 >= n || j + 2 >= m) continue;
			int tmpans = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			answer = max(tmpans, answer);
		}
	}
}
void shape5() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 1 >= n || j + 2 >= m) continue;
			int tmpans = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
			answer = max(tmpans, answer);
		}
	}
}

void shape5a() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 2 >= n || j - 1 < 0) continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j - 1];
			answer = max(tmpans, answer);
		}
	}
}
void shape5b() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j + 2 >= m || i - 1 < 0) continue;
			int tmpans = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i - 1][j + 1];
			answer = max(tmpans, answer);
		}
	}
}

void shape5c() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 2 >= n || j + 1 >= m)  continue;
			int tmpans = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
			answer = max(tmpans, answer);
		}
	}
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	}
	rectangle();
	spacebar();
	spacebar2();
	shape3();
	shape3a();
	shape3b();
	shape3c();
	shape3t();
	shape3ta();
	shape3tb();
	shape3tc();
	shape4();
	shape4a();
	shape4t();
	shape4ta();
	shape5();
	shape5a();
	shape5b();
	shape5c();

	
	cout << answer << endl;
	return 0;
}
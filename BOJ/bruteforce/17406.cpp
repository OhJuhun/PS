#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;


int N,M,K;
int arr[51][51];
struct item {
	int r, c, s;
};

vector<item> v;

void makeAns(int r,int c, int s) {

	int startX = r - s;
	int startY = c - s;
	int endX = r + s;
	int endY = c + s;
	if (s == 0) return;
	//상단을 ->로
	int tmp = arr[startX][endY];
	for (int i = endY; i > startY; i--) {
		arr[startX][i] = arr[startX][i - 1];
	}
	arr[startX][startY] = arr[startX + 1][startY];

	//오른쪽을 아래로
	int tmp2 = arr[endX][endY];
	for (int i = endX; i > startX+1; i--) {
		arr[i][endY] = arr[i - 1][endY];
	}
	arr[startX+1][endY] = tmp;
	tmp = arr[endX][startY];
	
	//아래쪽을 <로
	for (int i = startY; i < endY-1; i++) {
		arr[endX][i] = arr[endX][i + 1];
	}
	arr[endX][endY - 1] = tmp2;
	
	//왼쪽을 위로
	for (int i = startX + 1; i < endX - 1; i++) {
		arr[i][startY] = arr[i + 1][startY];
	}
	arr[endX - 1][startY] = tmp;
	makeAns(r, c, s - 1);
}

int getMin() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int tmp = 0;
		for (int j = 1; j <= M; j++) {
			tmp += arr[i][j];
		}
		if (!ans)
			ans = tmp;
		else if (ans > tmp)
			ans = tmp;
	}
	return ans;
}
int main(){
	cin >> N >> M >> K;
	int origin[51][51];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			origin[i][j] = arr[i][j];
		}
	}

	while (K--) {
		int r, c, s;
		cin >> r >> c >> s;
		v.push_back({ r,c,s });
	}

	vector<int> vv;

	for (int i = 0; i < v.size(); i++) {
		vv.push_back(i);
	}

	int ans = 0;

	do {
		for (int i = 0; i < vv.size(); i++) {
			int r, c, s;
			r = v[vv[i]].r;
			c = v[vv[i]].c;
			s = v[vv[i]].s;
			makeAns(r, c, s);
		}
		int tmp = getMin();
		if (ans == 0)
			ans = tmp;
		else if (tmp < ans)
			ans = tmp;

		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				arr[i][j] = origin[i][j];
		
	} while (next_permutation(vv.begin(), vv.end()));
	
	cout << ans << '\n';
	return 0;
}
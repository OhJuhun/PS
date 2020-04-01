#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


struct shark {
	int r, c, s, d, z;
};
int R, C, M;
int ans = 0;
int fisherman = 0;
vector<shark> sharks;
vector<int> arr[101][101];
int dir[5][2] = { {0,0},{-1,0},{1,0},{0,1},{0,-1} }; 

bool cmp(int a, int b) {
	return sharks[a].z > sharks[b].z;
}
void kill() {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (arr[i][j].size() <= 1) continue;
			sort(arr[i][j].begin(), arr[i][j].end(),cmp);
			int idx = arr[i][j][0];
			for (int k = 1; k < arr[i][j].size(); k++) {
				sharks[arr[i][j][k]].z = -1;
			}
			arr[i][j].clear();
			arr[i][j].push_back(idx);
		}
	}
	
}

void move() {
	//상어의 이동

	for (int i = 0; i < sharks.size(); i++) {
		if (sharks[i].z == -1) continue;
		arr[sharks[i].r][sharks[i].c].clear();
	}
	for (int i = 0; i < sharks.size(); i++) {
		if (sharks[i].z == -1) continue; //죽은 상어면 넘어감

		shark tmp = sharks[i];
	//	arr[sharks[i].r][sharks[i].c].pop_front(); //위치이동하니까 pop
		if (tmp.d == 1 || tmp.d == 2) {
			//위 또는 아래
			int rotate = (R - 1) * 2;
			if (tmp.s >= rotate) tmp.s = tmp.s%rotate;
			for (int j = 0; j < tmp.s; j++) {
				int dr = tmp.r + dir[tmp.d][0];
				int dc = tmp.c + dir[tmp.d][1];
				if (dr > R) {
					tmp.d = 1;
					dr -= 2;
				}
				if (dr < 1) {
					tmp.d = 2;
					dr += 2;
				}
				tmp.r = dr;
				tmp.c = dc;
			}
		}
		else {
			//좌 또는 우
			int rotate = (C - 1) * 2;
			if (tmp.s >= rotate) tmp.s = tmp.s%rotate;
			for (int j = 0; j < tmp.s; j++) {
				int dr = tmp.r + dir[tmp.d][0];
				int dc = tmp.c + dir[tmp.d][1];
				if (dc > C) {
					tmp.d = 4;
					dc -= 2;
				}
				if (dc < 1) {
					tmp.d = 3;
					dc+= 2;
				}
				tmp.r = dr;
				tmp.c = dc;
			}
		}
		tmp.s = sharks[i].s;
		sharks[i] = tmp;
		arr[sharks[i].r][sharks[i].c].push_back(i); //위치이동 했으니까 push
	}

}

void fishing() {
	while (++fisherman <= C) {
		
		for (int i = 1; i <= R; i++) {
			if (arr[i][fisherman].size() > 0) {
				//지금 행에 상어가 있으면 잡는다.
				int idx = arr[i][fisherman][0];//현재 상어의 인덱스를 찾는다
				arr[i][fisherman].pop_back();
				ans += sharks[idx].z;
				sharks[idx].z = -1; //상어의 크기를 -1로 바꾸어서 죽은 놈이라는 것을 알림
				break; //맨위에 상어만 잡으니까 break
			}
		}
		move();
		kill();
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C >> M;

	for(int i=0;i<M;i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		arr[r][c].push_back(i);
		//입력에 두마리가 한 곳에 오는 경우는 없다
		sharks.push_back({ r,c,s,d,z });
	}

	fishing();
	cout << ans << endl;
	return 0;
}
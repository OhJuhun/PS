#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
 
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321
 
struct cell {
    bool active = false; //활성 비활성
    bool live= true; //사망, live
    int x; //x초 후 활성
    int h; //생명력
    int r, c;
};
 
int N,M,K;
int arr[602][602]; //무한하지만 300이상으로 증가할 가능성은 없음
vector<cell> cells; // all cells
 
struct cmp {
    bool operator()(cell t, cell u) {
        return arr[t.r][t.c] < arr[u.r][u.c];
    }
};
priority_queue<cell, vector<cell>, cmp> activeCells;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
 
int countLive() {
    int ans = 0;
    for (cell c : cells) {
        if (c.live) {
            ans++;
        }
    }
    return ans;
}
void multiplication() {
    while (!activeCells.empty()) {
        //activeCells에 있는 놈들만
        cell f = activeCells.top();
        activeCells.pop();
        for (int i = 0; i < 4; i++) {
            cell n = f;
            n.r += dir[i][0];
            n.c += dir[i][1];
            n.active = false;
            n.live = true;
            n.x = arr[f.r][f.c];
            n.h = arr[f.r][f.c];
            if (arr[n.r][n.c] == 0) {
                //없는 상태일 때에만 증식
                arr[n.r][n.c] = n.x;
                cells.push_back(n);
            }
        }
    }
 
}
int solve() {
    int t = 0;
    while (K--) {
        for (int i = 0; i < cells.size(); i++) {
            if (cells[i].live) { //살아있는 셀만 관리
                //비활성인 것에 대해
                if (!cells[i].active) {
                    if (cells[i].x == 0) {
                        cells[i].active = true;
                        cells[i].h--;
                        if (cells[i].h == 0)
                            cells[i].live = false, cells[i].active = false;
                        activeCells.push(cells[i]);//현재 셀을 active 셀에 넣는다
                    }
                    else
                        cells[i].x--;
                }
                else {
                    //활성인 것에 대해
                    cells[i].h--;
                    if (cells[i].h == 0) {
                        cells[i].live = false;
                        cells[i].active = false;
                        //죽으면 끝남
                    }
                }
            }
            //죽은 셀은 관리 안함
        }
        multiplication();
    }
    return countLive();
}
void input() {
    memset(arr, 0, sizeof(arr));
    cells.clear();
    cin >> N >> M >> K;
    for (int i = 300; i < N + 300; i++) {
        for (int j = 300; j < M + 300; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                cell c;
                c.r = i;
                c.c = j;
                c.x = arr[i][j];
                c.h = c.x;
                cells.push_back(c);
            }
        }
    }
 
}
int main() {
    PREPROCESS;
 
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        input();
        cout << "#" << i << " " << solve() << '\n';
         
 
    }
    return 0;
}
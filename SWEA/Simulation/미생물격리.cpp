#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
 
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 98765432
 
struct microbe {
    int r, c, size, dir;
    bool live = true;
};
int N, M, K;
vector<int> arr[102][102];
microbe info[1001];
int dir[5][2] = { {0,0}, {-1,0},{1,0},{0,-1},{0,1} };
 
int cd(int d) {
    int ret;
    switch (d) {
    case 1:
        ret = 2;
        break;
    case 2:
        ret = 1;
        break;
    case 3:
        ret = 4;
        break;
    case 4:
        ret = 3;
        break;
    }
    return ret;
}
void move() {
    for (int i = 1; i <= K; i++) {
        if (!info[i].live) continue; //죽은 미생물
        info[i].r += dir[info[i].dir][0];
        info[i].c += dir[info[i].dir][1]; 
        //다음 위치 가로,세로
        if (info[i].r<1 || info[i].c<1 || info[i].r>=N-1 || info[i].c>=N-1) {
            //범위 밖으로 넘어갈 경우
            info[i].size /= 2;
            if (info[i].size == 0) {
                info[i].live = false;
                continue;
            } //죽은 경우
            info[i].dir = cd(info[i].dir); //끝에 도달했으니 방향 변경
        }
        arr[info[i].r][info[i].c].push_back(i); //i번은 현제 info[i].r / info[i].c의 위치에 있음
    }
}
 
void integrate() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            if (arr[i][j].empty()) continue;//비어있는 셀인경우 건너뛴다
            priority_queue<pair<int, int>> pq; //가장큰 size를 구분해내기 위한 큐
            for (int p : arr[i][j]) {
                pq.push(make_pair(info[p].size, p)); 
            }
            arr[i][j].clear();
            //pq로 옮긴 후 제거
            int idx = pq.top().second; //가장 큰놈을 가져옴
            pq.pop();
            while (!pq.empty()) {
                info[idx].size += pq.top().first;
                info[pq.top().second].size = 0;
                info[pq.top().second].live = false;
                pq.pop();
            }
        }
    }
}
void solve() {
    while (M--) {
        move();
        //이동 후 통합
        integrate();
         
    }
}
void input() {
    cin >> N >> M >> K;
    memset(info, 0, sizeof(info));
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++)
            arr[i][j].clear();
    }
    for (int i = 1; i <= K; i++) {
        cin >> info[i].r >> info[i].c >> info[i].size >> info[i].dir;
        info[i].live = true;
    }
}
int getAns() {
    int ret = 0;
    for (int i = 1; i <= K; i++) {
        ret += info[i].size;
    }
    return ret;
}
int main() {
    PREPROCESS;
 
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        solve();
        cout << "#" << t << " " << getAns() << '\n';
    }
    return 0;
}
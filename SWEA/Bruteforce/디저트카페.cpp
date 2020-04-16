#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
 
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 98765432
 
int N;
bool dessert[102];
int arr[22][22];
bool visit[22][22];
int ans = 0;
int dir[4][2] = { {1,1},{1,-1},{-1,1},{-1,-1} };
//대각 4방향
void dfs(int sr,int sc, int r, int c,int len,int cd,int befd) {
    if (r == sr && c == sc &&len!=0) {
        ans = max(ans, len);
        return;
    }
    visit[r][c] = true;
    dessert[arr[r][c]] = true;
    for (int i = 0; i < 4; i++) {
        int nextr = r + dir[i][0];
        int nextc = c + dir[i][1];
        int nextcd = befd != i ? cd+1 : cd;
        if (nextr == sr && nextc == sc) {
            dfs(sr, sc, nextr, nextc, len + 1, nextcd, i);
            continue;
        }
        if (nextr<1 || nextc<1 || nextr>N || nextc>N || dessert[arr[nextr][nextc]] || visit[nextr][nextc] || nextcd>=5) continue;
            //범위를 벗어나거나                         이미먹은 디저트이거나         이미 방문한 가게라면 가지않음
        dfs(sr, sc, nextr, nextc, len + 1,nextcd,i);
    }
    dessert[arr[r][c]] = false;
    visit[r][c] = false;
}
void solve() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if ((i == 1 && j == 1) || (i == 1 && j == N) || (i == N && j == N) || (i == N && j == 1)) continue;
            memset(dessert, false, sizeof(dessert));
            memset(visit, 0, sizeof(visit));
            dfs(i,j,i, j,0,0,-1);
        }
    }
}
void input() {
    cin >> N;
    memset(arr, 0, sizeof(arr));
    ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
}
 
 
int main() {
    PREPROCESS;
 
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        input();
        solve();
        cout << "#" << t << " " << (ans<=3 ? -1 : ans) << '\n';
 
    }
    return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;
 
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 98765432
 
struct item {
    int r, c, l;
};
int N,K;
int answer;
int arr[10][10];
int topHeight;
int I, J;
vector<pair<int, int>> tops;
int dir[4][2] = { {1,0},{0,1},{0,-1},{-1,0} };
bool visit[10][10];
void dfs(int r, int c,int l,int bef,bool first) {
    //r,c가 끝 봉우리이며 k는 시작점
    if ((!first) &&( r > N || c > N || r < 1 || c < 1 || arr[r][c] >= bef || visit[r][c])) {
        answer = max(answer, l);
        visit[r][c] = false;
        return;
    }
    visit[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nextr = r + dir[i][0];
        int nextc = c + dir[i][1];
        dfs(nextr, nextc, l + 1, arr[r][c], false);
    }
    visit[r][c] = false;
}
void solve() {
    while (K >= 0) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                //arr[i][j]의 값을 K만큼 줄인 후 시작
                arr[i][j] -= K;
                I = i, J = j;
                for (int k = 0; k < tops.size(); k++) {
                    if (K>0 && tops[k].first == i && tops[k].second == j) continue;
                        //줄인 곳이 최고 높이였던 곳이면 줄였을 때 최고 높이가 아니므로 불가능
                    memset(visit, false, sizeof(visit));
                    dfs(tops[k].first, tops[k].second,0,arr[tops[k].first][tops[k].second],true);
                }
                arr[i][j] += K;
                //다시 원상복귀
            }
        }
        K--;
    }
}
void input() {
    answer = 0;
    memset(arr, 0, sizeof(arr));
    cin >> N >> K;
    int tmpMax = 0;
    tops.clear();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            tmpMax = max(tmpMax,arr[i][j]);
        }
    }
    topHeight = tmpMax;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) { //모든 봉우리를 찾는다.
            if (arr[i][j] == tmpMax) tops.push_back(make_pair(i, j));
        }
    }
}
int main() {
    PREPROCESS;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        input();
        solve();
        cout << "#" << i << " " << answer << '\n';
    }
    return 0;
}
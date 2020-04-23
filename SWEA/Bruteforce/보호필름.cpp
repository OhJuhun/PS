#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321
int D, W, K;
bool arr[14][21];
bool tmparr[14][21];
bool correct = false;
vector<int> v;
 
void cpy() {
    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= W; j++)
            tmparr[i][j] = arr[i][j];
    }
}
bool check() {
    for (int j = 1; j <= W; j++) {
        int continous = 1;
        for (int i = 2; i <= D; i++) {
            if (tmparr[i][j] == tmparr[i - 1][j]) continous++;
            else continous = 1;
            if (continous >= K) //합격 기준에 만족했으면 break;
                break;
        }
        if (continous < K) return false;
    }
    return true;
}
//T개의 줄 변경
void dfs(int t,int T,int num) {
    if (num >= T+1) {
        correct = check();
        return;
    }
    for (int i = t; i <= D; i++) {
        //이 높이의 것을 바꾼다
        for (int j = 1; j <= W; j++) {
            tmparr[i][j] = 0;
        }
        //A로 변
        dfs(i + 1, T,num+1);
        if (correct) return;
        for (int j = 1; j <= W; j++)
            tmparr[i][j] = 1;
        dfs(i + 1, T, num + 1);
        if (correct)return;
        for (int j = 1; j <= W; j++) {
            tmparr[i][j] = arr[i][j];
        }
        if (correct)return;
    }
}
int solve() {
    int ret = 0;
    while (ret<=D) {
        cpy();
        dfs(1, ret,1);
        if (correct) return ret;
        ret++;
    }
}
void input() {
    cin >> D >> W >> K;
    correct = false;
    memset(arr, 0, sizeof(arr));
    memset(tmparr, 0, sizeof(tmparr));
    for (int i = 1; i <= D; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> arr[i][j];
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
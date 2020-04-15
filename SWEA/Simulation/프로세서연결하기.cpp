#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N;
int arr[13][13];
int maxCores = 0;
int ans;
vector<pair<int, int>> v;
 
bool top(int i, int j) {
    //위쪽으로 갈 수 있는지 확인
    for (int ii = 1; ii < i; ii++) {
        if (arr[ii][j]) return false;
    }
    return true;
}
bool left(int i, int j) {
    for (int jj = 1; jj < j; jj++) {
        if (arr[i][jj]) return false;
    }
    return true;
}
bool right(int i, int j) {
    for (int jj = j + 1; jj <= N; jj++)
        if (arr[i][jj]) return false;
    return true;
}
bool bottom(int i, int j) {
    for (int ii = i + 1; ii <= N; ii++) {
        if (arr[ii][j]) return false;
    }
    return true;
}
 
 
void topFill(int i, int j) {
    for (int ii = 1; ii < i; ii++) {
        arr[ii][j] = 2;
    }
}
void bottomFill(int i, int j) {
    for (int ii = i + 1; ii <= N; ii++) {
        arr[ii][j] = 2;
    }
}
void leftFill(int i, int j) {
    for (int jj = 1; jj < j; jj++) {
        arr[i][jj] = 2;
    }
}
void rightFill(int i, int j) {
    for (int jj = j + 1; jj <= N; jj++) {
        arr[i][jj] = 2;
    }
}
 
void topRemove(int i, int j) {
    for (int ii = 1; ii < i; ii++) {
        arr[ii][j] = 0;
    }
}
void bottomRemove(int i, int j) {
    for (int ii = i + 1; ii <= N; ii++) {
        arr[ii][j] = 0;
    }
}
void leftRemove(int i, int j) {
    for (int jj = 1; jj < j; jj++) {
        arr[i][jj] = 0;
    }
}
void rightRemove(int i, int j) {
    for (int jj = j + 1; jj <= N; jj++) {
        arr[i][jj] = 0;
    }
}
 
int sizeCheck() {
    int tmpans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == 2) tmpans++;
        }
    }
    return tmpans;
}
 
void getAns(int n,int cores) {//n번째 
    //위쪽, 왼쪽, 오른쪽, 아래쪽을 순서대로 연결해본다. backtrack
    if (n == v.size()) {
        //마지막 CORE를 확인할 때 사이즈 체크
        if (cores > maxCores) {
            ans = sizeCheck();
            maxCores = cores;
        }
        else if (cores == maxCores) {
            int tmp = sizeCheck();
            if (tmp < ans)
                ans = tmp;
        }
        return;
    }
    int i = v[n].first, j = v[n].second;
    if (top(i, j)) {//연결에 성공했을 때
        topFill(i, j);
        getAns(n + 1,cores+1);
        topRemove(i, j);
    }
    else {
        getAns(n + 1,cores);
    }
    if (left(i, j)) {
        leftFill(i, j);
        getAns(n + 1,cores+1);
        leftRemove(i, j);
    }
    else {
        getAns(n + 1, cores);
    }
    if (right(i, j)) {
        rightFill(i, j);
        getAns(n + 1, cores+1);
        rightRemove(i, j);
    }
    else {
        getAns(n + 1, cores);
    }
    if (bottom(i, j)) {
        bottomFill(i, j);
        getAns(n + 1,cores+1);
        bottomRemove(i, j);
    }
    else {
        getAns(n + 1,cores);
    }
}
 
void init() {
    maxCores = 0;
    ans = 0;
    v.clear();
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            arr[i][j] = 0;
        }
    }
}
int main(){
 
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> arr[i][j];
                if(arr[i][j]==1 && i!=1 && j!=1 && i!=N && j!=N)
                    v.push_back({ i,j });
            }
        }
        getAns(0, 0);
        cout << "#" << t << " " << ans << '\n';
        init();
    }
     
    return 0;
}
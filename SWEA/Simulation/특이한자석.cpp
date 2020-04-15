#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
 
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 100000001
#define MIN -100000001
int K;
bool magnet[4][8];
vector<pair<int,int>> dir; //회전할 자석 번호, 방향 1 시계 -1 반시계
void turn(int idx, int d) {
    int tmp[8];
    for (int i = 0; i < 8; i++)
        tmp[i] = magnet[idx][i];
    switch (d) {
    case 1: //시계방향
        for (int i = 1; i < 8; i++)
            magnet[idx][i] = tmp[i - 1];
        magnet[idx][0] = tmp[7];
        break;
    case -1://반시계방향
        for (int i = 0; i < 7; i++)
            magnet[idx][i] = tmp[i + 1];
        magnet[idx][7] = tmp[0];
        break;
    }
}
void solve() {
    for (pair<int, int> d : dir) {
        vector<pair<int, int>> move;
        int befd = d.second;
        switch (d.first) {
        case 0:
            move.push_back(make_pair(d.first, d.second));
            for (int i = 0; i < 3; i++) {
                if (magnet[i][2] != magnet[i+1][6]) {
                    //둘이 다른 극일 경우 둘다 움직임
                    //뒤에껀 다른 방향으로
                    int nextD = befd == 1 ? -1 : 1;
                    befd = nextD;
                    move.push_back(make_pair(i + 1, nextD));
                }
                else {
                    break;
                }
            }
            break;
        case 1:
            move.push_back(make_pair(d.first, d.second));
            if (magnet[0][2] != magnet[1][6]) {
                int nextD = befd == 1 ? -1 : 1;
                move.push_back(make_pair(0, nextD));
            }
            for (int i = 1; i < 3; i++) {
                if (magnet[i][2] != magnet[i + 1][6]) {
                    int nextD = befd == 1 ? -1 : 1;
                    befd = nextD;
                    move.push_back(make_pair(i + 1, nextD));
                }
                else
                    break;
            }
            break;
        case 2:
            move.push_back(make_pair(d.first, d.second));
            if (magnet[2][2] != magnet[3][6]) {
                int nextD = befd == 1 ? -1 : 1;
                move.push_back(make_pair(3, nextD));
            }
            for (int i = 2; i > 0; i--) {
                if (magnet[i][6] != magnet[i - 1][2]) {
                    int nextD = befd == 1 ? -1 : 1;
                    befd = nextD;
                    move.push_back(make_pair(i - 1, nextD));
                }
                else break;
            }
            break;
        case 3:
            move.push_back(make_pair(d.first, d.second));
            for (int i = 3; i > 0; i--) {
                if (magnet[i][6] != magnet[i - 1][2]) {
                    int nextD = befd == 1 ? -1 : 1;
                    befd = nextD;
                    move.push_back(make_pair(i - 1, nextD));
                }
                else break;
            }
            break;
        }
        for (int i = 0; i < move.size(); i++)
            turn(move[i].first, move[i].second);
    }
}
void input() {
    dir.clear();
    cin >> K;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 8; j++)
            cin >> magnet[i][j];
    for (int i = 0; i < K; i++) {
        int idx, d;
        cin >> idx >> d;
        dir.push_back({ idx-1,d });
    }
}
 
int answer() {
    int ans = 0;
    for (int i = 0; i < 4; i++)
        if(magnet[i][0])
            ans += (1 << i);
 
    return ans;
}
int main() {
    PREPROCESS;
 
    int T;
    cin >> T;
    for (int t = 1; t <= T;t++) {
        input();
        solve();
        cout << "#" << t << " " << answer() << '\n';
    }
    return 0;
}
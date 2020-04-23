#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
 
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 987654321
 
int N, M;
vector<pair<int, int>> houses;
int ans = 0;
void check(int K) {
    int cost = K * K + (K - 1)*(K - 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            //현재 방범 시작 위치
            int serviced = 0;
            for (pair<int, int> house : houses) {
                //현재위치에서 집까지의 거리가 K 이하이면 가능
                if (abs(house.first - i) + abs(house.second - j) < K)
                    serviced++;
            }
            int earn = M * serviced;
            if (earn >= cost) ans = max(ans, serviced);
        }
    }
}
void solve() {
    int K = 1;
    while (K<=N) {
        K++;
        check(K);
    }
}
void input() {
    cin >> N >> M;
    houses.clear();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            bool R;
            cin >> R;
            if (R) houses.push_back(make_pair(i, j));
        }
    }
    ans = houses.empty() ? 0 : 1;
}
 
int main() {
    PREPROCESS;
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        input();
        solve();
        cout << "#" << i << " " << ans << '\n';
    }
    return 0;
}
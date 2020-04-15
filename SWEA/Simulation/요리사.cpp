#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
 
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 100000001
#define MIN -100000001
int N;
int S[2];
int arr[16][16];
int ans;
void solve() {
    bool comb[16];
    for (int i = 0; i < N / 2; i++)
        comb[i] = 0;
    for (int i = N / 2; i < N; i++)
        comb[i] = 1;
 
    do {
        vector<int> v1;
        vector<int> v2;
        S[0] = 0;
        S[1] = 0;
        for (int i = 0; i < N; i++) {
            if (comb[i]) {
                v1.push_back(i);
            }
            else
                v2.push_back(i);
        }
        for (int i = 0; i < v1.size(); i++) {
            //0,1,2,5
            for (int j = 0; j < v1.size(); j++) {
                S[0] += arr[v1[i]][v1[j]];
            }
        }
        for (int i = 0; i < v2.size(); i++) {
            //0,1,2,5
            for (int j = 0; j < v2.size(); j++) {
                S[1] += arr[v2[i]][v2[j]];
            }
        }
        ans = min(abs(S[0] - S[1]),ans);
        if (ans == 0) break;
    } while (next_permutation(comb, comb + N));
}
void input() {
    memset(S, 0, sizeof(S));
    memset(arr, 0, sizeof(arr));
    ans = MAX;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
}
int main() {
    PREPROCESS;
 
    int T;
    cin >> T;
    for (int t = 1; t <= T;t++) {
        input();
        solve();
        cout << "#" << t << " " << ans << '\n';
    }
    return 0;
}
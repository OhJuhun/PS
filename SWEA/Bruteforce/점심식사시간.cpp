#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
 
#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)
#define MAX 98765432
 
int N;
int arr[11][11];
vector<pair<int, int>> people;
vector<pair<int, int>> stair;
priority_queue<pair<int, int>> hole[2];
int comb[11];
int answer;
int go() {
    int time = 0;
//  cout << hole[0].size() << " " << hole[1].size() <<" ";
    queue<pair<int, int>> q[2]; //현재 들어있는 idx, 남은 시간
    while (true) {
    //  cout << "시간: " << time << " ";
        if (q[0].empty() && q[1].empty() && hole[0].empty() && hole[1].empty()) break;
        time++;
    //  cout << q[0].size() << " " << q[1].size() << " " << hole[0].size() << " " << hole[1].size() << endl;;
        if (!q[0].empty()) {
            int qsize = q[0].size();
            for (int i = 0; i < qsize; i++) {
                pair<int, int> p = q[0].front();
                q[0].pop();
                p.second--;
                if(p.second>0)
                    q[0].push(p);
            }
        }
        if (!q[1].empty()) {
            int qsize = q[1].size();
            for (int i = 0; i < qsize; i++) {
                pair<int, int> p = q[1].front();
                q[1].pop();
                p.second--;
                if (p.second>0)
                    q[1].push(p);
            }
        }
            while (!hole[0].empty() && time + hole[0].top().first>=0) {
                //도달 시간에 맞으면
                if (q[0].size() == 3 || hole[0].empty()) {
                    break;
                }
                q[0].push(make_pair(hole[0].top().second, arr[stair[0].first][stair[0].second]));
                hole[0].pop();
            }
            while (!hole[1].empty() && time + hole[1].top().first>=0 ) {
                if (q[1].size() == 3 || hole[1].empty()) {
                    break;
                }
                q[1].push(make_pair(hole[1].top().second, arr[stair[1].first][stair[1].second]));
                hole[1].pop();
            }
         
    }
    //cout << time << endl;
    return time;
}
void dfs(int n) {
    if (n == people.size()) {
        int ans = 0;
        while (!hole[0].empty()) hole[0].pop();
        while (!hole[1].empty()) hole[1].pop();
        for (int i = 0; i < people.size(); i++){
            int dis = abs(people[i].first - stair[comb[i]].first) + abs(people[i].second - stair[comb[i]].second);
            hole[comb[i]].push(make_pair(-dis, i)); 
        }
        answer=min(answer,go());
        return;
    }
    for (int i = 0; i < 2; i++) {
        comb[n] = i;
        dfs(n + 1);
    }
}
void solve() {
    //i번 사람이 stair 0으로 갈지, 1로 갈지 결정 
    dfs(0);
}
void input() {
    cin >> N;
    people.clear();
    stair.clear();
    memset(arr, 0, sizeof(arr));
    answer = MAX;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) people.push_back(make_pair(i, j)); //사람들의 위치
            if (arr[i][j] > 1) stair.push_back(make_pair(i, j)); //계단의 위치
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
        cout << "#" << t << " " << answer+1 << '\n';
    }
    return 0;
}
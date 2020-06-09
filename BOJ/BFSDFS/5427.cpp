#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;
#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
#define INF 987654321;
char arr[1001][1001];
int w,h;
queue<pair<int,int> > sg;
queue<pair<int, int> > fire;
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
bool visit[1001][1001];
int solve(){
    int ret = 0;
    visit[sg.front().first][sg.front().second] = true;
    while(!sg.empty()){
        ret++;
        int fsize = fire.size();
        for(int i=0;i<fsize;i++){
            pair<int,int> cur = fire.front();
            fire.pop();
            visit[cur.first][cur.second] = true;
            for(int i=0;i<4;i++){
                pair<int,int> next = make_pair(cur.first+dir[i][0],cur.second+dir[i][1]);
                if(next.first>=h || next.second>=w || next.first<0 || next.second<0 || 
                arr[next.first][next.second]!='.' || visit[next.first][next.second]) continue;
                arr[next.first][next.second]='*';
                fire.push(next);
                visit[next.first][next.second] = true;
            }
        }
        int ssize = sg.size();
        for(int i=0;i<ssize;i++){
            pair<int,int> cur = sg.front();
            sg.pop();
            if(cur.first==h-1 || cur.second==w-1 || cur.first==0 || cur.second==0) return ret;
            for(int i=0;i<4;i++){
                pair<int,int> next = make_pair(cur.first+dir[i][0],cur.second+dir[i][1]);
                if(arr[next.first][next.second]!='.' || visit[next.first][next.second]) continue;
                sg.push(next);
                visit[next.first][next.second]= true;
            }
        }
    }
    
    return -1;
}
void input(){
    cin>>w>>h;
    memset(visit,0,sizeof(visit));
    while(!sg.empty()) sg.pop();
    while(!fire.empty()) fire.pop();
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='@'){
                arr[i][j]='.';
                sg.push(make_pair(i,j));
            }
            if(arr[i][j]=='*'){
                fire.push(make_pair(i,j));
                visit[i][j]= true;
            }
        }
    }
}
int main(){
    fastio;
    int T;
    cin>>T;
    while(T--){
        input();
        int answer = solve();
        cout<< (answer == -1 ? "IMPOSSIBLE" : to_string(answer))<<'\n';
    }
    return 0;
}
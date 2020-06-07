#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
#define INF 987654321;

string str;
int N;
pair<int,int> home;
pair<int,int> festa;
pair<int,int> store[101];
bool visit[101];
bool solve(){
    queue<pair<int,int> > q;
    q.push(home);
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(abs(festa.first-cur.first)+abs(festa.second-cur.second)<=1000) return true;
        for(int i=0;i<N;i++){
            if(visit[i]) continue;
            pair<int,int> next = store[i];
            if(abs(next.first-cur.first)+abs(next.second-cur.second)<=1000){
                q.push(next);
                visit[i]=true;
            }
        }
    }
    return false;
}
void input(){
    cin>>N;
    cin>>home.first>>home.second;
    memset(visit,false,sizeof(visit));
    memset(store,0,sizeof(store));
    for(int i=0;i<N;i++) cin>>store[i].first>>store[i].second;
    cin>>festa.first>>festa.second;

}
int main(){
    fastio;
    int t;
    cin>>t;
    while(t--){
        input();
        cout<<(solve() ? "happy\n" : "sad\n");
    }
    return 0;
}
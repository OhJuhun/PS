#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0), cout.tie(0)

int N,T,G;

int answer[100000];

int btnA(int n){
    return n+1;
}
int btnB(int n){
    if(n==0) return 0;
    int i=1;
    n*=2;
    while(n/i>0) i*=10;
    n = n - (i/10);
    return n;
}
void solve(){
    queue<pair<int,int> > q;
    q.push(make_pair(N,0));
    answer[N]=0;
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        if(cur.second>T) break;
        int nb = btnB(cur.first);
        if(cur.first*2<100000 && answer[nb]>cur.second+1){
            answer[nb]=cur.second+1;
            q.push(make_pair(nb,cur.second+1));
        }
        int na = btnA(cur.first);
        if(na<100000 && answer[na]>cur.second+1){
            answer[na] = cur.second+1;
            q.push(make_pair(na,cur.second+1));
        }
    }
    
}
void input(){
    cin>>N>>T>>G;
    for(int i=0;i<100000;i++) answer[i]=100000;
}
int main(){
    fastio;
    input();
    solve();
    if(answer[G]>T) cout<<"ANG\n";
    else cout<<answer[G]<<'\n';
    return 0;
}
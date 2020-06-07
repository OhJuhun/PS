#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
#define INF 987654321;

struct channel{
    int num;
    int cnt;
    bool ud; //true : up, down btn
    
};
int N,M;
bool btn[10];
bool visit[1000001][2];
int answer = 0;

int solve(){
    queue<channel> q;
    channel first;
    first.num=100;
    first.cnt=0;
    first.ud=true;
    q.push(first);
    visit[100][0]=true;
    
    while(!q.empty()){
        channel cur = q.front();
        q.pop();
        if(cur.num==N){
            return cur.cnt;
        }
        
        for(int i=0;i<10;i++){
            if(btn[i]) continue;
            channel next= cur;
            if(next.ud){
                next.num=i;
            }
            else{
                next.num*=10;
                next.num+=i;
            }
            next.ud= false;
            next.cnt++;
            if(next.num>1000000 || next.num<0|| visit[next.num][1]) continue;
            
            q.push(next);
            visit[next.num][1]=true;
        }
        if(!visit[cur.num+1][0] && cur.num+1<=1000000){
            //아직 방문하지 않은 채널
            channel next = cur;
            next.num++;
            next.cnt++;
            next.ud=true;
            q.push(next);
            visit[next.num][0]=true;
        }
        if(!visit[cur.num-1][0] && cur.num-1>=0){
            channel next = cur;
            next.num--;
            next.cnt++;
            next.ud=true;
            q.push(next);
            visit[next.num][0]=true;
        }
    }
}
void input(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int t;
        cin>>t;
        btn[t]=true;
    }
}
int main(){
    fastio;
    input();
    cout<<solve();
    
    return 0;
}
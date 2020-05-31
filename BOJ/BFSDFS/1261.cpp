#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0), cout.tie(0)

struct triple{
    int r,c,v;
};

int N,M;
char arr[100][100];
int ans[100][100];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

int solve(){
    ans[0][0]=0;
    queue<triple> q;
    triple tmp = {0,0,0};
    q.push(tmp);
    while(!q.empty()){
        triple cur = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            triple next = {cur.r+dir[i][0],cur.c+dir[i][1], cur.v};
            if(next.r>=M || next.c>=N || next.r<0 || next.c<0) continue; //oor
            if(arr[next.r][next.c]=='1'){
                if(ans[next.r][next.c]<=next.v+1) continue;
                ans[next.r][next.c]=++next.v;
                q.push(next);
            }
            else{
                if(ans[next.r][next.c]<=next.v) continue;
                ans[next.r][next.c]=next.v;
                q.push(next);
            }
        }
    }
    return ans[M-1][N-1];
}
void input(){
    cin>>N>>M;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    memset(ans,10001,sizeof(ans));
}
int main(){
    fastio;
    input();
    cout<<solve()<<'\n';
    return 0;
}
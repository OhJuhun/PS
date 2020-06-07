#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
#define INF 987654321;
int R,C;
char arr[21][21];
int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int answer=0;
void dfs(int r,int c,bool container[],int cnt){
    if(r>=R || r<0 || c>=C || c<0 || container[arr[r][c]-'A']){
        answer = max(answer,cnt);
        return;
    }
    container[arr[r][c]-'A']=true;
    for(int i=0;i<4;i++){
        dfs(r+dir[i][0],c+dir[i][1],container,cnt+1);
    }
    container[arr[r][c]-'A'] = false;
}
int main(){
    fastio;

    cin>>R>>C;
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) cin>>arr[i][j];
    bool con[26];
    for(int i=0;i<26;i++) con[i]= false;
    dfs(0,0,con,0);
    cout<<answer<<endl;
    return 0;
}
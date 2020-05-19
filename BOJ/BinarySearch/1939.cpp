#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N,M;
vector<pair<int,int> > v[10001];
int S,E;

bool bfs(int T){
    //target
    queue<int> q;
    q.push(S);
    bool visit[10001];
    memset(visit,0,sizeof(visit));
    visit[S]=true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur==E) return true;
        for(pair<int,int> p : v[cur]){
            //다음 위치 탐색
            if(p.second<T  || visit[p.first]) continue;
            q.push(p.first);
            visit[p.first]=true;
            
        }
    }
    return false;
}
int main(){
    cin>>N>>M;
    int l = 0, r = 0;
    for(int i=0;i<M;i++){
        int from, to,c;
        cin>>from>>to>>c;
        v[from].push_back(make_pair(to,c));
        v[to].push_back(make_pair(from,c));
        //다리 연결
        r = max(c,r);
    }
    cin>>S>>E;
    int answer = 0;
    while(l<=r){
        int m = (r+l)/2;
        if(bfs(m)){
            answer = max(m,answer);
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    cout<<answer<<endl;
    
    return 0;
}



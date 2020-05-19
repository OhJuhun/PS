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
    for(int i=0;#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,K;
long long M;
vector<pair<long long,long long> > vp;


const bool cmp(pair<long long,long long> a, pair<long long, long long> b ){
    return a.first>b.first;
}
bool bs(long long m){
    long long tmpM = 0;
    int cnt = 0;
    for(pair<long long,long long> p : vp){
        if(p.second<=m){
            tmpM+=p.first, cnt++;
            if(cnt==N) break;
        }
    }

    return tmpM>=M && cnt==N;
}
int main(){
    cin>>N>>M>>K;
    long long l = 0, r = 0;
    for(int i=0;i<K;i++){
        long long a,b;
        cin>>a>>b;
        vp.push_back(make_pair(a,b));
        r = max(r,b);
    }
    sort(vp.begin(),vp.end(),cmp);
    long long answer = r;
    bool flag = false;
    while(l<=r){
        long long m = (l+r)/2;
        if(bs(m)){
            answer = min(answer,m);
            flag = true;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    cout<< (flag ? answer : -1)<<'\n';
    return 0;
}i<M;i++){
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



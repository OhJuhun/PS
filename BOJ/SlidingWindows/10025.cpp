#include <iostream>
#include <algorithm>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0), cout.tie(0)

long long g[1000001];
int main(){
    PREPROCESS;
    int N,K;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        int x,b;
        cin>>x>>b;
        g[b]=x;
    }
    long long answer = 0;
    int cur = K;
    for(int i=0;i<=cur+K;i++){
        answer+=g[i];
    }
    long long tmp = answer;
    for(int i=K+1;i<=1000000-K;i++){
        tmp-=g[i-K-1];
        tmp+=g[i+K];
        answer = max(tmp,answer);
    }
    cout<<answer<<'\n';
    
    return 0;
}
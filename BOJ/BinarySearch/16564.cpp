#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)


bool isPossible(long long T, vector<long long> v, long long K){
    for(long long level : v){
        if(level<T)
            K -= (T-level);
    }
    return K>=0;
}
int main() {
    fastio;
    int N,K;
    cin>>N>>K;
    vector<long long> v(N);
    for(int i=0;i<N;i++) cin>>v[i];

    sort(v.begin(),v.end());
    long long l = 1;
    long long r = 1000000000;
    long long ans = 1;
    while(l<=r){
        long long m = (l+r)/2; //목표 레벨
        if(isPossible(m,v,K)){
            ans= max(ans,m);
            l=m+1;
        }
        else{
            r=m-1;
        }
    }
    cout<<ans<<endl;
}

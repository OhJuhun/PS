#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)

bool isPossible(long long mid, vector<long long> v, long long m){
    for(int i=0;i<v.size();i++){
        m-=mid/v[i];
    }
    return m<=0;
}
int main() {
    fastio;
    long long n,m;
    cin>>n>>m;
    vector<long long> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    sort(v.begin(),v.end());
    long long l = 1;
    long long r = v.back()*m;
    long long ans =r;
    while(l<=r){
        long long mid = (l+r)/2;
        if(isPossible(mid,v,m)){
            //가능하면 소요시간을 더 줄인다
            ans = min(ans,mid);
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}

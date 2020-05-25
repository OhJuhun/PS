#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        if(n<=k){
            cout<<1<<'\n';
            continue;
        }
        int ans= 1;
        for(int i=sqrt(n);i>=1;i--){
            if(n%i==0 && k>=i){
                if(i< n/i){
                    if(k>=n/i){ //조건 부합
                        ans=max(ans,n/i);
                    }
                    else ans = max(ans,i);
                }
                else ans = max(ans,i);
                
            }
        }
        cout<<n/ans<<'\n';
    }
    return 0;
}
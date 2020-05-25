
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        int m = min(a,b);
        int M = max(a,b);
        m=2*m;
        int ans = max(M,m);
        cout<<ans*ans<<'\n';
    }

}
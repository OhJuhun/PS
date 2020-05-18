#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
int main(){
    fastio;
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        cin>>m;
        for(int i=0;i<m;i++){
            int t;
            cin>>t;
            int l = 0,r=n-1;
            bool flag = false;
            while(l<=r){
                int mid = (l+r)/2;
                if(v[mid]==t){
                    flag = true;
                    break;
                }
                if(v[mid]>t) r=mid-1;
                else l=mid+1;
            }
            cout<<flag<<"\n";
        }
    }
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
int main(){
    
    fastio;
    int N,M;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;i++) cin>>arr[i];
    sort(arr.begin(),arr.end());
    cin>>M;
    for(int i=0;i<M;i++){
        int t;
        cin>>t;
        int l = 0, r = N-1;
        bool flag = false;
        while(l<=r){
            int m = (l+r)/2;
            if(arr[m]==t){
                flag = true;
                break;
            }
            else if(arr[m]>t) r = m -1;
            else l = m + 1;
        }
        cout<<flag<<' ';
    }
    return 0;
}
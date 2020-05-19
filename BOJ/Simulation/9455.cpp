#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int m,n;
        int arr[101][101];
        cin>>m>>n;
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) cin>>arr[i][j];
        int ans=0;
        for(int j=0;j<n;j++){
            int cnt=0;
            for(int i=m-1;i>=0;i--){
                if(arr[i][j]==0) cnt++;
                else{
                    arr[i+cnt][j]=1;
                    ans += cnt;
                    arr[i][j]=0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
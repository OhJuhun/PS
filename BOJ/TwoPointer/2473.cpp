#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long arr[5000];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    long long ans[3]={arr[0],arr[1],arr[n-1]};
    for(int i=0;i<n;i++){
        int l =i+1;
        int r =n-1;
        while(l<r){
            if(abs(arr[i]+arr[l]+arr[r])<abs(ans[0]+ans[1]+ans[2])){
                ans[0]=arr[i],ans[1]=arr[l],ans[2]=arr[r];
                r--;
            }
            else{
                if(arr[i]+arr[l]+arr[r]>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
    }
    sort(ans,ans+3);
    for(int i=0;i<3;i++) cout<<ans[i]<<" ";
    return 0;

}
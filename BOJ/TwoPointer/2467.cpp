#include <iostream>

using namespace std;

#define PREPROCESS ios_base::sync_with_stdio, cin.tie(0),cout.tie(0)

int main(){
    int n;
    cin>>n;
    int arr[100000];
    for(int i=0;i<n;i++) cin>>arr[i];

    int ansL=arr[0];
    int ansR=arr[n-1];

    int l =0;
    int r = n-1;
    while(l<r){
        if(abs(arr[r]+arr[l])<abs(ansR+ansL)){
            ansR=arr[r],ansL=arr[l];
        }
        if(arr[r]+arr[l]>0){
            r--;
        }
        else{
            l++;
        }
    }
    cout<<ansL<<" "<<ansR<<'\n';
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[100000];
    int n;
    int x;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    cin>>x;
    int l = 0,r=n-1;
    int sum = 0;
    int answer = 0;
    sum =arr[l]+arr[r];
    while(l<r){
        if(sum==x){
            answer++;
            sum-=arr[r];
            r--;
            sum+=arr[r];
        }
        else if(sum<x){
            sum-=arr[l];
            l++;
            sum+=arr[l];
        }
        else{
            sum-=arr[r];
            r--;
            sum+=arr[r];
        }

    }
    cout<<answer<<endl;
    return 0;
}
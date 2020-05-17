#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,k;
    int arr[100000];
    cin>>n>>k;
    int answer = 0,sum=0;
    for(int i=0;i<n;i++) cin>>arr[i];
    int l=0,r=k-1;
    for(int i=0;i<k;i++) sum +=arr[i];
    //0~k-1
    answer = sum;
    for(int i=1;i<n-k+1;i++){
        answer =max(answer,sum);
        sum -= arr[i-1];
        sum+=arr[i+k-1];
        
    }
    answer = max(answer,sum);
    cout<<answer<<endl;
    return 0;
}
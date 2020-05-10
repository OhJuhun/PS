#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio,cin.tie(0),cout.tie(0);

int main(){
    int n,m;
    cin>>n>>m;
    int arr[100001];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int l = 0;
    int r = 0;
    int dis = arr[n-1]-arr[l];
    bool flag =true;
    while(r<=n-1){
        if(m<=arr[r]-arr[l]) dis = min(dis,arr[r]-arr[l]),l++;
        else r++;
    }
    cout<<dis<<endl;

}
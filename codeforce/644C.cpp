#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[50];
        int odds= 0;
        int even = 0;
        for(int i=0;i<n;i++){
          cin>>arr[i];
          arr[i] % 2 == 0 ? even++ : odds++;
        }
        if(even%2==0 && odds%2==0){
            cout<<"YES\n";
            continue;;
        }
        sort(arr,arr+n);
        bool flag= false;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==1){
                cout<<"YES\n";
                flag = true;
                break;
            }
            //1 3 4 5
        }
        if(!flag) cout<<"NO\n";
    }

}

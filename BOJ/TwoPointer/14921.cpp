#include <iostream>
using namespace std;

int main(){
    int N;
    int arr[100000];
    cin>>N;
    for(int i=0;i<N;i++) cin>>arr[i];
    int l =0;
    int r = N-1;
    int answer = arr[r]+arr[l];
    while(l<r){
        if(abs(arr[r]+arr[l])<abs(answer)){
            answer = arr[r]+arr[l];
            r--;
        }
        else if(arr[r]+arr[l]<0){
            l++;
        }
        else r--;
    }
    cout<<answer<<'\n';
    return 0;
}
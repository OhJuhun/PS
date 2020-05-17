#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[1000000];
    int doll[3]={0,0,0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        doll[arr[i]]++;
    }
    if(doll[1]<k){
        cout<<-1<<'\n';
        return 0;
    }
    
    int answer = n;
    int l = 0; //시작
    int lions = 0;
    for(int i=0;i<n;i++){
        if(arr[i]==1) lions++;
        if(lions == k){
            answer = min(answer,i-l+1);
            l++;
            lions--;
        }
        while(arr[l]==2) l++;

    }
    cout<<answer<<endl;
    return 0;
}
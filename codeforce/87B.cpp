#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int arr[4]= { 0,0,0,0};
        for(int i=0;i<str.length();i++){
            arr[str[i]-'0']++;
        }
        if(arr[1]==0 || arr[2]==0 || arr[3]==0){
            cout<<0<<'\n';
            continue;
        }//안되는 경우
        int answer = str.length();
        int len = str.length();
        int l =0,r=0;
        arr[1]=0,arr[2]=0,arr[3]=0;
        arr[str[0]-'0']++;
        while(r<len && l<=r){
            if(arr[1] && arr[2] && arr[3]){
                //셋다 차있으면 
                answer = min(answer,r-l+1);
                arr[str[l]-'0']--;
                l++;
                
            }
            else{
                r++;
                arr[str[r]-'0']++;
            }
        }
        cout<<answer<<'\n';
    }
    return 0;
}
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n,d,k,c;
    int arr[30000];
    map<int,int> used;
    cin>>n>>d>>k>>c;
    for(int i=0;i<n;i++) cin>>arr[i];
    //0은 n-1과 연결
    int cnt=1;
    int answer =0;
    used[c]=1;
    for(int i=0;i<k;i++){
        if(used[arr[i]]==0){
            cnt++;
            used[arr[i]]++;
        }
        else{
            used[arr[i]]++;
        }
    }
    answer =  cnt;
    for(int i=1;i<n;i++){
        //현재 시작점 i, 끝점 i+k-1
        int s = i;
        int e = i+k-1;
        e %=n;
        //맨 앞을 뺀다
        used[arr[s-1]]--;
        if(used[arr[s-1]]==0) cnt--;
        if(used[arr[e]]==0) cnt++;
        used[arr[e]]++;
        answer = max(cnt,answer);
        
    }
    cout<<answer<<endl;
    return 0;
}
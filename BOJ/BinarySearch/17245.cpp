#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N;
long long arr[1001][1001];
long long allSum = 0;

bool bs(int m){
    long long sum = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!arr[i][j]) continue;
            sum += arr[i][j]>=m ? m : arr[i][j];
        }
    }
    return sum>=allSum;
}
int main(){
    cin>>N;
    long long l=0,r=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
            allSum+=arr[i][j];
            r= max(arr[i][j],r);
        }
    }
    allSum = allSum&1 ? allSum/2+1 : allSum/2;
    long long answer = r;
    while(l<=r){
        long long m = (l+r)/2;
        if(bs(m)){
            //m은 타겟숫자 이므로 시간을 더 줄일 수 잇음을 의미
            r = m -1;
            answer = min(answer,m);
        }
        else l=m+1;
    }
    cout<<answer<<'\n';
    return 0;
}
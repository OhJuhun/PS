#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int answer =0;
    int l=1;
    int r= 1;
    int sum = 1;
    while(l<=r){
        if(sum==N){
            answer++;
            sum-=l;
            l++;
        }
        else if(sum<N){
            r++;
            sum+=r;
        }
        else{
            sum-=l;
            l++;
        }
    }
    cout<<answer<<'\n';
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        a-=b;
        if(a<=0){
            cout<<b<<'\n';
            continue;
        }
        //남은 시간 a분을 더자야하는데 C분후 알람이 울리고, d분후 잠이듬 그러므로 자는 시간은 c-d분
        long long sleeping=c-d;
        if(sleeping<=0){
            cout<<-1<<'\n';
            continue;
        }
        int x = a%sleeping ==0 ? a/sleeping : a/sleeping+1;
        cout<<b+x*c<<'\n';
    }
    return 0;
}
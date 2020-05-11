#include <iostream>

using namespace std;

#define PREPROCESS ios_base::sync_with_stdio,cin.tie(0),cout.tie(0);

int main(){
    int G;
    cin>>G;
    long long before=1;
    long long current=1;
    bool flag= false;
    while(before<=current && before<=100000 && current<=100000){
        if(current*current - before*before == G){
            cout<<current<<'\n';
            current++;
            flag = true;
        }
        else if(current*current-before*before>G){
            before++;
        }
        else{
            current++;
        }
    }
    if(!flag) cout<<-1<<endl;
    return 0;
}
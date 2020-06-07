#include <iostream>
#include <algorithm>
#include <string>s
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
#define INF 987654321;

string str;
int N,M;

int solve(){
    int pattern=0;
    int ret = 0;
    for(int i=1;i<str.length()-1;i++){
        if(str[i]=='O' && str[i-1]=='I' && str[i+1]=='I'){
            pattern++;
            if(pattern==N){
                pattern --;
                ret++;
            }
            i++;
        }
        else pattern=0;
    }
    return ret;
}
void input(){
    cin>>N>>M>>str;
}
int main(){
    fastio;
    input();
    cout<<solve()<<'\n';
    return 0;
}
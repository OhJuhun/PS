#include <iostream>
#include <algorithm>

using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
#define INF 987654321;

int arr[7];

void input(){
    int sum = 0;
    int mini = -1;
    for(int i=0;i<7;i++){
        cin>>arr[i];
        if(arr[i]&1){
            sum+=arr[i];
            mini = mini==-1 ? arr[i] : min(arr[i],mini);
        }
    }
    if(mini == -1) cout<<-1<<'\n';
    else cout<<sum<<'\n'<<mini<<'\n';
}
int main(){
    fastio;
    input();
    return 0;
}
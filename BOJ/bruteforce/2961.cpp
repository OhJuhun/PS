#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
#define INF 987654321;

int main(){
    fastio;
    vector<pair<int,int> > vp;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        vp.push_back(make_pair(a,b));
    }
    int answer = INF;
    for(int i=1;i<=n;i++){
        vector<bool> arr;
        for(int j=0;j<i;j++) arr.push_back(1);
        for(int j=i;j<n;j++)arr.push_back(0);
        
        do{
            int a=1,b=0;
            for(int j=0;j<n;j++){
                if(arr[j]) a*=vp[j].first,b+=vp[j].second;
            }
            answer = min(answer,abs(a-b));
        }while(prev_permutation(arr.begin(),arr.end()));
    }
 
    cout<<answer<<'\n';
    return 0;
}
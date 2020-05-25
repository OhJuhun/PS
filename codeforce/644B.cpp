
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int answer = abs(v[0]-v[1]);
        for(int i=1;i<n;i++){
            answer = answer>abs(v[i-1]-v[i]) ? abs(v[i-1]-v[i]) : answer;
        }

        cout<<answer<<'\n';

    }

    return 0;
}
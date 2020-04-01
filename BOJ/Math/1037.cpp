#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v;
    while(N--){
        int k;
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    cout<<v[0]*v[v.size()-1]<<endl;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int N;
    cin>>N;
    while(N--){
        int K;
        cin>>K;
        v.push_back(K);
    }
    if(next_permutation(v.begin(),v.end())){
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    else
        cout<<-1<<endl;
}
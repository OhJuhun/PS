#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    unsigned int S;
    cin>>S;
    int N=0;
    long long sum = 0;
    int i=1;
    while(sum<=S){
        sum+=i++;
        N++;
    }
    cout<<N-1<<'\n';
    return 0;
}
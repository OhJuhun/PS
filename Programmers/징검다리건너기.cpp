#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool bs(vector<int> v,int k,int m){
    int cnt=0;
    for(int i=0;i<v.size();i++){
        if(v[i]-m<=0) cnt++;
        else cnt=0;
        if(cnt>=k) return false;
        
    }
    return true;
}
int solution(vector<int> stones, int k) {
    int MAX=0;
    int MIN=200000000;
    for(int i=0;i<stones.size();i++){
        MAX=max(stones[i],MAX);
        MIN=min(stones[i],MIN);
    }
    while(MIN<=MAX){
        int mid = MIN+MAX;
        mid/=2;
        if(bs(stones,k,mid)){
            MIN=mid+1;
        }
        else{
            MAX=mid-1;
        }
    }

    return MIN;
}
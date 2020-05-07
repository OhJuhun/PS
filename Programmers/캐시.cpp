#include <string>
#include <vector>
#include <map>
using namespace std;

map<string,int> LRU;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    if(cacheSize==0) return cities.size()*5;
    for(string city:cities){
        for(int i=0;i<city.size();i++){
            if(city[i]>='A' && city[i]<='Z')
                city[i]=tolower(city[i]);
        }
        if(LRU[city]==0){
            LRU[city]=1; 
            answer+=5;
            int maxval=0,maxidx=0; //혹시 쫓아내게 된다면 사용할 idx
            for(int i=0;i<cache.size();i++){
                LRU[cache[i]]++;
                //더 전에 사용했음을 알림
                if(LRU[cache[i]]>maxval) maxval=LRU[cache[i]],maxidx=i;
            }
            if(cache.size()>=cacheSize){
                //캐시가 가득 찼을 경우
                LRU[cache[maxidx]] = 0;
                cache[maxidx] = city;
            }
            else{
                //캐시가 가득차지 않았을 경우
                cache.push_back(city);
            }
        } //cache miss 새로 캐시에 넣어야 함
        else{
            answer++;
            for(int i=0;i<cache.size();i++){
                LRU[cache[i]]++;
            }
            LRU[city]=1;
        } //cache hit 캐시에 넣을 필요 없음
    }
    return answer;
}
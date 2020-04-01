#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;


map<long long,long long> parent;

long long Find(long long x){
    if(!parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for(int i=0;i<room_number.size();i++){
        if(!parent[room_number[i]]){
            answer.push_back(room_number[i]);
            parent[room_number[i]]=Find(room_number[i]+1);
        }
        else{
            long long tmp = Find(room_number[i]);
            answer.push_back(tmp);
            parent[tmp]=Find(tmp+1);
        }
    }

    return answer;
}
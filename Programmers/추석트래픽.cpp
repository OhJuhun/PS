#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<int,int>> time;
    for(string line : lines){
        bool flag = false;
        string endT="";
        string usedT;
        for(int i=0;i<line.length();i++){
            if(!flag){
                if(line[i]==' ') flag = true;
                continue;
            }
            if(line[i]==' '){
                usedT=line[i+1];
                usedT+=line.substr(i+3,line.length()-i-4);
                break;
            }
            if(line[i]==':'  || line[i]=='.') continue;
            endT+=line[i];
        }
        if(usedT.length()<4){
            int len = usedT.length();
            for(int i=0;i<4-len;i++)
                usedT+="0";
        }
        cout<<stoi(endT)%10000000<<" "<<stoi(usedT)<<endl;
        time.push_back({stoi(endT)-stoi(usedT)+1,stoi(endT)+999});
    }
    sort(time.begin(),time.end());
    int startT=time[0].first; //시작시간중 제일 앞
    int endT = time.back().second; //끝 시간 중 마지막
    priority_queue<int,vector<int>,greater<int>> pq;
    int idx=0;
    for(int i=0;i<time.size();i++){
        if(time[i].first%10000000>9000000){
            time[i].first -=4000000;
        }
        if(time[i].first%100000>90000)
            time[i].first-=40000;
    }
    for(int i=startT;i<=endT;i++){
        while(idx<time.size() && time[idx].first<=i) pq.push(time[idx].second),idx++;
        answer = max(answer,(int)pq.size());
        while(!pq.empty() && pq.top()<=i) pq.pop();
    }
    return answer;
}
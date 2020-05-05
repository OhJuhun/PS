#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(),stages.end());
    vector<pair<float,int>> vp;
    int s=0;
    for(int i=1;i<=N;i++){
        float frate = 0;
        int people=0;
        bool flag = false;
        for(int j=s;j<stages.size();j++){
            if(stages[j]==i) people++; //현재 이 stage에 있는 사람의 수
            else if(stages[j]>i){
                //다음이 나왔다면 계산
                frate = (float)people/((int)stages.size()-s);
                s=j;
                flag = true;
                break;
            }
        }
        if(!flag){
            frate = (float)people/((int)stages.size()-s);
        }
        vp.push_back(make_pair(-frate,i));
    }
    sort(vp.begin(),vp.end());
    for(int i=0;i<vp.size();i++)
        answer.push_back(vp[i].second);
    return answer;
}
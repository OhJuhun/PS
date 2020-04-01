#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


bool cmp(vector<int> a,vector<int> b){
    return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> tmp;
    int num=0;
    vector<int> v;
    for(int i=2;i<s.length()-1;i++){
        if(s[i]=='{'){
            continue;
        }
        else if(s[i]=='}'){
            v.push_back(num);
            num=0;
            tmp.push_back(v);
            i++;
            v.clear();
        }
        else if(s[i]==','){
            v.push_back(num);
            num=0;
        }else{ //숫자일 경우
            num*=10;
            num+=s[i]-'0';
        }
    }
    sort(tmp.begin(),tmp.end(),cmp);
    for(int i=0;i<tmp.size();i++){
        for(int j=0;j<tmp[i].size();j++){
            bool flag=true;
            for(int k=0;k<answer.size();k++){
                if(tmp[i][j]==answer[k]){
                    flag=false;
                    break;
                }
            }
            if(flag) answer.push_back(tmp[i][j]);
        }
    }

    return answer;
}
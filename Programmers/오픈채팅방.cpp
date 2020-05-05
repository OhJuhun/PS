#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

struct info{
    string id;
    int inorout; //0은 인 1은 아웃
};
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> hash;
    vector<info> inout;
    for(string r : record){
            string id="";
            string nickname="";
            bool flag = false;
        if(r.substr(0,5)=="Enter"){
            for(int j=6;j<r.length();j++){
                if(r[j]==' '){
                    flag = true;
                    continue;
                }
                if(!flag){
                    id+=r[j];
                }
                else if(flag){
                    nickname+=r[j];
                }
            }
            hash[id]=nickname;
            info inf ={id,0};
            inout.push_back(inf);
        }
        else if(r.substr(0,5)=="Leave"){
            for(int j=6;j<r.length();j++){
                id+=r[j];
            }
            info inf ={id,1};
            inout.push_back(inf);
        }
        else{
            for(int j=7;j<r.length();j++){
                if(r[j]==' '){
                    flag = true;
                    continue;
                }
                if(!flag){
                    id+=r[j];
                }
                else{
                    nickname+=r[j];
                }
            }
            hash[id]=nickname;
        }
    }
    for(int i=0;i<inout.size();i++){
        if(!inout[i].inorout){
            answer.push_back(hash[inout[i].id]+"님이 들어왔습니다.");
        }
        else{
            answer.push_back(hash[inout[i].id]+"님이 나갔습니다.");
        }
    }
    return answer;
}
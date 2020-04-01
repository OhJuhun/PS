#include <string>
#include <vector>
#include <iostream>
#include <set>


using namespace std;

int last;
int perm[10];
set<set<string>> ans;
void getAns(vector<string> cand[10],int idx){
    if(idx==last){
        set<string> tmpset;
        for(int i=0;i<idx;i++){
            tmpset.insert(cand[i][perm[i]]);
        }
        if(tmpset.size()==last){
            ans.insert(tmpset);
        }
    }
    for(int i=0;i<cand[idx].size();i++){
        perm[idx]=i;
        getAns(cand,idx+1);
    }
    
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<string> cand[10];
    last=banned_id.size();
    for(int i=0;i<banned_id.size();i++){
        for(int j=0;j<user_id.size();j++){
            bool flag=true;
            if(banned_id[i].length()!=user_id[j].length()) continue;
            for(int k=0;k<user_id[j].length();k++){
                if(banned_id[i][k]=='*') continue;
                if(user_id[j][k]!=banned_id[i][k]){
                    flag= false;
                    break;
                }
            }
            if(flag) cand[i].push_back(user_id[j]);
        }
    }
    getAns(cand,0);
    return ans.size();
}
#include <string>
#include <vector>
using namespace std;

int arr[26];
int st[26];
int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(int i=1;i<skill.length();i++)
        arr[skill[i]-'A']=1,st[skill[i]-'A']=1;
    for(string skill_tree : skill_trees){
        for(int i=0;i<26;i++){
            st[i]=arr[i];
        }
        bool flag= true;
        int idx = 0;
        for(char sk : skill_tree){
            if(st[sk-'A']==1){
                flag = false;
                break; 
            }
            if(skill[idx]==sk && idx+1<skill.length()){
                idx++;
                st[skill[idx]-'A']=0;
            }
        }
        if(flag) answer++;
    }
    
    return answer;
}
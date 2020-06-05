#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string, bool> MAP;
    int human=1,order=1;
    MAP[words[0]]=true;
    bool flag = true;
    for(int i=1;i<words.size();i++){
        if(!MAP[words[i]] && words[i-1].back()==words[i][0]){
            MAP[words[i]]=true;
            human++;
            human%=n;
            if(human==0) order++;
        }
        else{
            flag = false;
            break;
        }
    }
    if(!flag){
        answer.push_back(human+1);
        answer.push_back(order);
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}
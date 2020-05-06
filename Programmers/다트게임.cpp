#include <string>
#include <iostream>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    char prize[3] = {'n','n','n'};
    int score[3];
    string s="";
    int idx=0;
    for(int i=0;i<dartResult.length();i++){
        if(dartResult[i]>='0' && dartResult[i]<='9'){
            //숫자 범위 내
            s+=dartResult[i];
        }
        else if(dartResult[i]=='S'){
            score[idx++]=stoi(s);
            s="";
        }
        else if(dartResult[i]=='D'){
            score[idx++]=stoi(s)*stoi(s);
            s="";
        }
        else if(dartResult[i]=='T'){
            score[idx++]=stoi(s)*stoi(s)*stoi(s);
            s="";
        }
        else if(dartResult[i]=='*'){
            prize[idx-1]='*';
        }
        else if(dartResult[i]=='#'){
            prize[idx-1]='#';
        }
    }
    cout<<score[0]<<" "<<score[1]<<" "<<score[2]<<" "<<prize[0]<<" "<<prize[1]<<" "<<prize[2]<<endl;
    if(prize[0]=='*') score[0]*=2;
    if(prize[1]=='*') score[1]*=2,score[0]*=2;
    if(prize[2]=='*') score[1]*=2,score[2]*=2;
    cout<<score[0]<<" "<<score[1]<<" "<<score[2]<<endl;
    for(int i=0;i<3;i++){
        if(prize[i]=='#') score[i]*=-1;
        answer+=score[i];
    }
    return answer;
}
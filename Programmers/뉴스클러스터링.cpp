#include <string>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int mul = 65536;
int solution(string str1, string str2) {
    int answer = 0;
    string tmp="";
    for(int i=0;i<str1.length();i++){
        if(str1[i]>='A' && str1[i]<='Z'){
            str1[i]=tolower(str1[i]);
        }
    }
    tmp="";
    for(int i=0;i<str2.length();i++){
        if(str2[i]>='A' && str2[i]<='Z'){
            str2[i]=tolower(str2[i]);
        }
    }
    vector<string> A;
    vector<string> B;
    map<string,int> mA;
    map<string,int> mB;
    for(int i=0;i<str1.length()-1;i++){
        if(str1[i]>='a' && str1[i]<='z' &&str1[i+1]>='a' && str1[i+1]<='z'){
            A.push_back(str1.substr(i,2));
            mA[str1.substr(i,2)]++;
        }
    }
        
    for(int i=0;i<str2.length()-1;i++){
        if(str2[i]>='a' && str2[i]<='z' && str2[i+1]>='a' && str2[i+1]<='z'){
            B.push_back(str2.substr(i,2));
            mB[str2.substr(i,2)]++;
        }
    }
    int AnB=0;
    int AUB=0;
    for(string str : A){
        //교집합 수구하기
        AnB += min(mA[str],mB[str]);
        AUB += max(mA[str],mB[str]);
        mA[str]=0,mB[str]=0;
    }
    for(string str: B){
        if(mA[str]==0){
            AUB+=mB[str];
            mB[str]=0;
        }
    }
    answer = AUB == 0 ? mul : mul*AnB / AUB;
    return answer;
}
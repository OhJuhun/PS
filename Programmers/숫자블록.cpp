#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;


vector<int> solution(long long begin, long long end) {
    //소수일 경우 1
    //소수가 아닐 경우 가장 큰 약수 = n/2
    vector<int> answer;
    for(long long i=begin;i<=end;i++){
        if(i==1){
            answer.push_back(0);
            continue;
        }
        bool flag = true;
        for(long long j=2;j<=sqrt(i)+1;j++){
            if(i%j==0 && i/j<=10000000){
                answer.push_back(i/j);
                flag = false;
                break;
            }
        }
        if(flag) answer.push_back(1);
    }
    return answer;
}
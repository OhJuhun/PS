#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;

bool use[7];
set<int> answer;
bool prime[9999999];
void eratos(){
    memset(prime,true,sizeof(prime));
    for(int i=2;i<=sqrt(9999999);i++){
        if(!prime[i]) continue;
        for(int j=i+i;j<=9999999;j+=i){
            prime[j]=false;
        }
    }
    prime[0]=0;
    prime[1]=0;
}
int toInt(string str){
    int digit = 1;
    int ans=0;
    for(int i=str.length()-1;i>=0;i--){
        ans+=(str[i]-'0')*digit;
        digit*=10;
    }
    return ans;
}

void recursive(int i,string str){
    if(i==str.length()){
        string tmp ="";
        for(int j=0;j<str.length();j++)
            if(use[j]) tmp+=str[j];
        int n = toInt(tmp);
        if(prime[n]){
            answer.insert(n);
        } 
        return;
    }
    for(int j=0;j<2;j++){
        use[i]=j;
        recursive(i+1,str);
    }
}
int solution(string numbers) {
    eratos();
    sort(numbers.begin(),numbers.end());
    do{
        recursive(0,numbers);
    }while(next_permutation(numbers.begin(),numbers.end()));
    
    return answer.size();
}
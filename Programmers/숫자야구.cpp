#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    for(int N=123;N<=987;N++){
        string str=to_string(N);
        bool flag= true;
        if(str[0]==str[1] || str[1]==str[2]||str[2]==str[0]) continue;
        if(str[0]=='0' || str[1]=='0' || str[2]=='0') continue;
        
        for(int k=0;k<baseball.size();k++){
            int s=0,b=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(str.at(i)==to_string(baseball[k][0]).at(j) ){
                        if(i==j)
                            s++;
                        else b++;
                        continue;
                    }
                }
            }
            if(baseball[k][1]!=s || baseball[k][2]!=b){
                flag=false;
                break;
            }
        }
        if(flag) answer++;
    }
    return answer;
}
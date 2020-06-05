#include <string>
using namespace std;

string solution(int n) {
    string answer = "";
    //0->4 1->1 2->2
    //1 2 4 11 12 14 21 22 24 41
    //1 2 3  4  5  6  7  8  9 10
    while(n>0){
        if(n%3==0){
            answer = "4"+answer;
            n-=1;
        }
        else if(n%3==1) answer = "1"+answer;
        else answer="2"+answer;
        n/=3;
    }
    return answer;
}
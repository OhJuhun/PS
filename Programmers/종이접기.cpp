#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(0);
    n--;
    while(n--){
        int len = answer.size();
        answer.push_back(0);
        for(int i=len-1;i>=0;i--){
            answer.push_back(answer[i]^1);
        }
    }
    return answer;
}
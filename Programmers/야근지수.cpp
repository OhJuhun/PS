#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> q;
    for(int work: works) q.push(work);
    while(!q.empty() && n--){
        int c = q.top()-1;
        q.pop();
        if(c>0) q.push(c);
    }
    while(!q.empty()){
        answer+=q.top()*q.top();
        q.pop();
    }
        
    
    return answer;
}
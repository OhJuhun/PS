#include <vector>
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(string token:tokens){
            if(token=="*"){
                int val = num.top();
                num.pop();
                val*=num.top();
                num.pop();
                num.push(val);
            }
            else if(token=="/"){
                int val = num.top();
                num.pop();
                int val2 = num.top();
                val2/=val;
                num.pop();
                num.push(val2);
            }
            else if(token=="+"){
                int val = num.top();
                num.pop();
                val+=num.top();
                num.pop();
                num.push(val);
            }
            else if(token=="-"){
                int val = -num.top();
                num.pop();
                val+=num.top();
                num.pop();
                num.push(val);
            }
            else{
                num.push(stoi(token));
            }
        }
        return num.top();
    }
};
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        int answer = 0;
        for(char c : S){
            if(c=='('){
                st.push('(');
            }
            else if(c==')' && !st.empty())
                st.pop();
            else{
                answer++;
            }
        }
        return answer + st.size();
    }
};
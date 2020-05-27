#include <vector>

using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> answer;
        int sum = 0;
        for(int i : A){
            sum*=2;
            sum+=i;
            sum%=5;
            sum==0 ? answer.push_back(1) : answer.push_back(0);
        }
        return answer;
    }
};
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> answer;
        int dp[30000];
        dp[0]=arr[0];
        for(int i=1;i<arr.size();i++)
            dp[i]=arr[i]^dp[i-1];
        for(vector<int> query : queries){
            if(query[0]==query[1]) answer.push_back(arr[query[0]]);
            else if(query[0]==0) answer.push_back(dp[query[1]]);
            else answer.push_back(dp[query[1]]^dp[query[0]-1]);
        }
        return answer;
    }
};
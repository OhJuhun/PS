#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int comp = nums[nums.size()/2];
        int answer = 0;
        for(int num : nums){
            answer += abs(comp-num);
        }
        return answer;
    }
};
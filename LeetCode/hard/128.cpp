#include <vector>
#include <map>
#include <algorithm>

using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> m;
        int ans = 0;
        for (int num : nums) {
            if (m.count(num)) continue;
            
            auto it_l = m.find(num - 1);
            auto it_r = m.find(num + 1);
            
            int l = it_l != m.end() ? it_l->second : 0;
            int r = it_r != m.end() ? it_r->second : 0;
            int t = l + r + 1;
            
            m[num] = m[num - l] = m[num + r] = t;
            
            ans = max(ans, t);            
        }
        return ans;
    }
};
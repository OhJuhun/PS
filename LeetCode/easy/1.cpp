#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        int ptr=0,ptr2=nums.size()-1;
        vector<int> ans;
        bool flag=false;
        while(ptr<ptr2){
            if(v[ptr].first+v[ptr2].first==target){
                flag=true;
                break;
            }
            else if(v[ptr].first+v[ptr2].first>target){
                ptr2--;
            }
            else
                ptr++;
            
        }
        if(flag){
            ans.push_back(v[ptr].second);
            ans.push_back(v[ptr2].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
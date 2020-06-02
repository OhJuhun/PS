#include <vector>
#include <algorithm>

using namespace std;
int cmpVal;
bool cmp( int a,  int b){
    if(a==cmpVal) return false;
    if(b==cmpVal) return true;
    return a<b;
}
class Solution {
public:
   
    int removeElement(vector<int>& nums, int val) {
        cmpVal=val;
        int s = nums.size();
        sort(nums.begin(),nums.end(),cmp);
        int cnt=0;
        while(!nums.empty() && nums.back()==val){
            nums.pop_back();
            cnt++;
        }
        return s-cnt;
    }
};
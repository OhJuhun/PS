#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        for(int i=1;i<=n;i++) v.push_back(i);
        
        while(--k) next_permutation(v.begin(),v.end());
        
        string answer;
        for(int i : v)
            answer+=to_string(i);
        
        return answer;
    }
};
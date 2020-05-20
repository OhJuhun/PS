#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int countSegments(string s) {
        vector<string> ret;
        string tmp="";
        for(char c : s){
            if(c==' '){
                if(tmp!="")
                    ret.push_back(tmp);
                tmp="";
            }
            else tmp+='c';
        }
        if(tmp!="") ret.push_back(tmp);
        
        return ret.size();
        
    }
};
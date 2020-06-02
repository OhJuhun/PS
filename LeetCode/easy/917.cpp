#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string S) {
        string answer="";
        int idx=0;
        vector<int> special;
        for(int i=0;i<S.length();i++){
            if((S[i]>='a' && S[i]<='z' ) || (S[i]>='A' &&S[i]<='Z')) continue;
            special.push_back(i);
        }
        int j=0;
        for(int i=S.length()-1;i>=0;i--){
            if(j<special.size() && idx==special[j]){
                answer+=S[idx];
                j++;
                i++;
                
            }
            else{
                if((S[i]>='a' && S[i]<='z' ) || (S[i]>='A' &&S[i]<='Z')) answer+=S[i];
                else idx--;
                
            }
            idx++;
        }
        while(j<special.size()) answer+=S[special[j++]];
        return answer;
    }
};
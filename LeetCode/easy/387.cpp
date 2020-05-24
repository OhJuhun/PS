#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int answer=-1;
        int MAP[26];
        for(int i=0;i<26;i++) MAP[i]=0;
        for(char c : s) MAP[c-'a']++;
        
        for(int i=0;i<s.length();i++)
            if(MAP[s[i]-'a']==1) return i;
        return -1;
    }
};
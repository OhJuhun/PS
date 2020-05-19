#include <string>

using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        const int len = palindrome.length();
        for(int i=0;i<len/2;i++){
            if(palindrome[i]=='a') continue;
            palindrome[i]='a';
            return palindrome;
        }
        return len == 1 ? "" : palindrome.substr(0,len-1)+'b';
    }
};

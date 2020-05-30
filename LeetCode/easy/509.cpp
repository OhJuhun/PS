#include <algorithm>

class Solution {
public:
    int fib(int N) {
        int a = 0;
        int b = 1;
        for(int i=2;i<=N;i++){
            i%2==0? a+=b : b+=a;
        }
        return N==0 ? 0 : std::max(a,b);
    }
};
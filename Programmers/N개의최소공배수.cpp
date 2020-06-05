#include <string>
#include <vector>

using namespace std;

int gcd(int a,int b){
    return b==0 ? a : gcd(b,a%b);
}
int lcm(int a,int b){
    return a*b / gcd(a,b);
}
int solution(vector<int> arr) {
    int answer = 1;
    
    for(int i=0;i<arr.size();i++)
        answer = lcm(arr[i],answer);
    return answer;
}
#include <string>
#include <vector>

using namespace std;

int sum[2000];
int solution(vector<int> cookie) {
    int answer = 0;
    sum[0]= cookie[0];
    for(int i=1;i<cookie.size();i++)
        sum[i]= sum[i-1]+cookie[i];
    for(int m=0;m<cookie.size();m++){
        int a = sum[m]; //0~m까지 합
        for(int r=m+1;r<cookie.size();r++){
            //m+1~N까지 합
            int b = sum[r]-a;
            if(answer>b) continue;
            if(a==b){
                answer = max(answer,b); //후보군일 경우
                break;
            }
            else if(a<b){
                //b가 더 크면 후보군이 생길 수 없음
                break;
            }
            else{
                //a>b이면 a를 줄여나가면서 후보군을 찾음
                bool flag = false;
                for(int l=0;l<m;l++){
                    int c = a-sum[l];
                    if(c==b){
                        answer = max(answer,c);
                        break;
                    }
                    else if(c<b){
                        break;
                    }
                }
            }
        }
    }
    return answer;
}
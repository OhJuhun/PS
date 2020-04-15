#include <iostream>
#include <stack>
using namespace std;
int test_case;
int T;
int K;
int arr[100001];
int solution() {
    int ans=0;
    stack<int> st;
    for (int i = 0; i < K; i++) {
        if (arr[i] == 0) {//잘못 불린 수인 경우
            st.pop();
        }
        else { //제대로 불린 수인 경우
            st.push(arr[i]);
        }
    }
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}
int main(int argc, char** argv)
{
 
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin>>K;
        for (int j = 0; j < K; j++) {
            cin >> arr[j];
        }
        cout <<"#"<<test_case<<" "<< solution() << endl;
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
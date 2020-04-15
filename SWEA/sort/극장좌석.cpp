#include <iostream>
#include <algorithm>
using namespace std;
 
int main(int argc, char** argv){
    int T;
    cin >> T;
    for(int t=1;t<=T;t++) {
        int N,ans=0;
        int arr[10001];
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            ans += arr[i];
        }
        ans += N;
        sort(arr, arr + N);
        ans += arr[N - 1];
        cout << "#" << t << " " << ans << '\n';
         
    }
}
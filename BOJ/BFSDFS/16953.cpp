#include <iostream>

using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
int answer=987654321;
void dfs(long long A,long long B,int ans){
	//A를 B로
	if(A>B) return;
	if(A==B){
		answer=min(answer,ans);
		return;
	}
	dfs(A*2,B,ans+1);
	dfs(A*10+1,B,ans+1);
}
int main(){
	fastio;
	int A,B;
	cin>>A>>B;
	dfs(A,B,1);
	cout<<(answer == 987654321 ? -1 : answer)<<endl;
}
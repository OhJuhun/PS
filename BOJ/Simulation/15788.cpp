#include <iostream>
#include <set>
using namespace std;

int N;
long long arr[502][502];
int x,y;
int main(){
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>arr[i][j];
			if(arr[i][j]==0){
				x=i;
				y=j;
			}
		}
	}
	long long equalSumcnt=0;
	long long realSum=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			arr[i][N+1]+=arr[i][j];
			arr[N+1][j]+=arr[i][j];
			if(i==j){
				arr[N+1][N+1]+=arr[i][j];
			}
			if(i+j==N+1){
				arr[0][N+1]+=arr[i][j];
			}	
		}
		if(realSum<arr[i][N+1])
			realSum=arr[i][N+1];
	}
	long long ans=-1;
	long long cnt=0;
	for(int i=0;i<=N+1;i++){
		cnt++;
		if(arr[i][N+1]==realSum)
			equalSumcnt++;
	}
	for(int i=0;i<=N;i++){
		cnt++;
		if(arr[N+1][i]==realSum)
			equalSumcnt++;
	}
	cnt-=1;
	if(x==y && x+y==N+1){ //대각을 포함할 경우,가운데값일경우
		if(arr[N+1][N+1]==arr[N+1][y] && arr[x][N+1]==arr[N+1][N+1] && arr[0][N+1]==arr[N+1][N+1]){
			if(equalSumcnt==cnt-4)
				ans=realSum-arr[N+1][N+1];
		}
	}
	else if(x==y && x+y!=N+1){
		if(arr[N+1][N+1]==arr[N+1][y] && arr[x][N+1]==arr[N+1][N+1]){
			//모두값이같으면 true
			if(equalSumcnt==cnt-3)
			ans=realSum-arr[N+1][N+1];		
		}
	}
	else if(x!=y && x+y==N+1){
		if(arr[N+1][y]==arr[0][N+1] && arr[x][N+1]==arr[0][N+1])	
			if(equalSumcnt==cnt-3)
				ans=realSum-arr[N+1][y];
	}
	else{
		if(arr[N+1][y]==arr[x][N+1] && equalSumcnt==cnt-2)
			ans=realSum-arr[N+1][y];
	}
	
	cout<<ans<<endl;
	return 0;
}

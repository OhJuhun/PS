#include <iostream>

using namespace std;

unsigned int num[10001][5001];

long long c(int n,int r){
	if(num[n][r]!=0) return num[n][r];
	if(n==r || r==0) return num[n][r]=1;
	else{
		num[n][r] = (c(n-1,r-1))%1000000007+(c(n-1,r))%1000000007;
		return num[n][r];
	}
}
int main(){
	int N,M; //N<=10000 2<=M<=100
	cin>>N>>M; //N : fight time // M : Skill using Time
	long long cnt=0;
	for(int a=0;a<=N;a++){//a+b*M=N
		for(int b=0;b*M+a<=N;b++){
			if(N==a+b*M){
				cnt+=c(a+b,b);
				cnt%=1000000007;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

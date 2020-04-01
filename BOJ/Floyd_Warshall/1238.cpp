#include <iostream>

using namespace std;

#define INF 987654321;
int main(){
	int arr[1001][1001];
	int N,M,X;
	cin>>N>>M>>X;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			arr[i][j]=INF;
			if(i==j)
				arr[i][j]=0;
		}
	}
	
	for(int i=0;i<M;i++){
		int from,to,cost;
		cin>>from>>to>>cost;
		if(arr[from][to]>cost)
			arr[from][to]=cost;
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=N;k++){
				arr[j][k]=min(arr[j][k],arr[j][i]+arr[i][k]);
			}
		}
	}
	int sum[1001];
	int maxx=-1;
	for(int i=1;i<=N;i++){
		sum[i]=arr[i][X]+arr[X][i];
		if(sum[i]>maxx)
			maxx=sum[i];
	}
	cout<<maxx<<endl;
	return 0;
}
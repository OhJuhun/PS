#include <iostream>

using namespace std;

#define INF 100001;
int main(){
	int n,m;
	int bus[101][101];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			bus[i][j]=INF;
			if(i==j) bus[i][j]=0;
		}
	}
	for(int i=0;i<m;i++){
		int from, to, cost;
		cin>>from>>to>>cost;
		if(bus[from][to]>cost){
			bus[from][to]=cost;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				bus[j][k]=min(bus[j][k],bus[j][i]+bus[i][k]);
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		if(bus[i][j]==100001)
			cout<<0<<" ";
		else
			cout<<bus[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
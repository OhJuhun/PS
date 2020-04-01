#include <iostream>

using namespace std;

int main(){
	int N,M; //N=1, M<=100
	int A[101];
	int B[101];
	bool toggle[101];
	int K;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>A[i]>>B[i];
		toggle[i]=true;
	} //true = front, false = back
	for(int i=0;i<M;i++){
		cin>>K;
		for(int j=0;j<N;j++){
			if(toggle[j] && A[j]<=K)
				toggle[j]=false;
			else if(!toggle[j] && B[j]<=K)
				toggle[j]=true;
		}
	}
	
	int sum=0;
	for(int i=0;i<N;i++){
		if(toggle[i])
			sum+=A[i];
		else
			sum+=B[i];
	}
	cout<<sum<<endl;
	return 0;
}
#include <iostream>

using namespace std;

	
int main(){
int arr[100][100];
bool visit[100][100];
int N;
	cin>>N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			cin>>arr[i][j];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(arr[i][j] && arr[j][k])
					arr[i][k]=1;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(arr[i][j] && arr[j][k])
					arr[i][k]=1;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
}

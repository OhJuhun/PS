#include <iostream>
#include <string>
using namespace std;

int num[26]={3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,
	2,2,1,2,1,1,1,2,2,1};
int main(){
	int N,M;
	string n1,n2; //Name1,Name2
	int ans[202];
	int ans2[202];
	cin>>N>>M;
	cin>>n1>>n2;
	int maxi=N>M?N:M;
	string hap="";
	for(int i=0;i<maxi;i++){
		if(i<N)
			hap+=n1.at(i);
		if(i<M)
		hap+=n2.at(i);
	}
	int numHap=hap.length();
	for(int i=0;i<numHap;i++) //획수
		ans[i]=num[(int)hap.at(i)-65];
	bool Ok=true;
	while(numHap!=2){
		if(Ok){ //ans -> ans2
			for(int i=0;i<numHap-1;i++){
				ans2[i]=(ans[i]+ans[i+1])%10;
			}
			Ok=false;
			ans[numHap-1]=0;
		}
		else{ //ans2->ans
			for(int i=0;i<numHap-1;i++){
				ans[i]=(ans2[i]+ans2[i+1])%10;
			}
			ans2[numHap-1]=0;
			Ok=true;
		}
		
		numHap--;
	}
	if(Ok){
		if(ans[0]==0)
			cout<<ans[1]<<"%"<<endl;
		else
			cout<<ans[0]<<ans[1]<<"%"<<endl;
	}
	else{
		if(ans2[0]==0)
			cout<<ans2[1]<<"%"<<endl;
		else
			cout<<ans2[0]<<ans2[1]<<"%"<<endl;
	}
}
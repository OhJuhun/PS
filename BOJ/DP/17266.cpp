#include <iostream>

using namespace std;
int ways[100002];
int main(){
	int N,M;
	int light;
	int longest=0;
	int aq=0;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>light;
		ways[light]=1;
	}
	if(M==1){
        cout<<N<<endl;
        return 0;
    }
	bool first=true;
	//first light check
	for(int i=0;i<=N;i++){
		if(ways[i]==0){ //light off
			aq++;
		}
		else{ //light on
			if(first){ // first light
				longest=aq;
				first=false;
			}
			else{ //after second light
				aq+=1;
				if(aq%2==1 &&longest<aq/2+1){ // odd number
					longest=aq/2+1;
				}
				else if(aq%2==0 && longest<aq/2){
					longest=aq/2;
				}
			}
			aq=0;
		}
	}
	
	if(longest<aq)//last
		longest=aq;
	cout<<longest<<endl;
	
	return 0;
}

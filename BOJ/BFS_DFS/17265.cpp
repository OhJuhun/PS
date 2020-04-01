#include <iostream>
#include <queue>
using namespace std;

char m[6][6];
bool visit[6][6];
int mini=999999;
int maxi=-999999;
struct item{
	int i;
	int j;
	int sum;
	char opt;
};
int calc(int x,int y, char sig){
	if(sig=='+') return x+y;
	if(sig=='-') return x-y;
	if(sig=='*') return x*y;
	if(sig=='/') return x/y;
}

void bfs(int N){
	queue<item> q;
	item it;
	it.i=1;
	it.j=1;
	it.sum=m[1][1]-48;
	q.push(it);
	visit[1][1]=true;
	while(!q.empty()){
		item itc=q.front();
		visit[itc.i][itc.j]=true;
		q.pop();
		if(itc.i==N && itc.j==N){
			if(maxi<=itc.sum)
				maxi=itc.sum;
			if(mini>=itc.sum)
				mini=itc.sum;
			continue;
		}
		if(itc.i+1<=N && !visit[itc.i+1][itc.j]){ //down
			item itn;
			itn.i=itc.i+1;
			itn.j=itc.j;
			if(m[itc.i+1][itc.j]>=48 && m[itc.i+1][itc.j]<=57){ // if it is number
				itn.sum=calc(itc.sum,m[itc.i+1][itc.j]-48,itc.opt);
			}
			else{
				itn.sum=itc.sum;
				itn.opt=m[itc.i+1][itc.j];
			}
			q.push(itn);
		}
		if(itc.i-1>=1 && !visit[itc.i-1][itc.j]){ //up
			item itn;
			itn.i=itc.i-1;
			itn.j=itc.j;
			if(m[itc.i-1][itc.j]>=48 && m[itc.i-1][itc.j]<=57){
				itn.sum=calc(itc.sum,m[itc.i-1][itc.j]-48,itc.opt);
			}
			else{
				itn.sum=itc.sum;
				itn.opt=m[itc.i-1][itc.j];
			}
			q.push(itn);
		}
		if(itc.j+1<=N && !visit[itc.i][itc.j+1]){ //right
			item itn;
			itn.i=itc.i;
			itn.j=itc.j+1;
			if(m[itc.i][itc.j+1]>=48 && m[itc.i][itc.j+1]<=57){
				itn.sum=calc(itc.sum,m[itc.i][itc.j+1]-48,itc.opt);
			}
			else{
				itn.sum=itc.sum;
				itn.opt=m[itc.i][itc.j+1];
			}
			q.push(itn);
		}
		if(itc.j-1>=N && !visit[itc.i][itc.j-1]){ //left
			item itn;
			itn.i=itc.i;
			itn.j=itc.j-1;
			if(m[itc.i][itc.j-1]>=48 && m[itc.i][itc.j-1]<=57){
				itn.sum=calc(itc.sum,m[itc.i][itc.j-1]-48,itc.opt);
			}
			else{
				itn.sum=itc.sum;
				itn.opt=m[itc.i][itc.j-1];
			}
			q.push(itn);
		}
		
	}
	cout<<maxi<<" "<<mini<<endl;
}

int init(int N){
	cin>>N;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			cin>>m[i][j];

	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			visit[i][j]=false;
	return N;
}
int main(){
	int N;
	N=init(N);
	bfs(N);
	return 0;
}

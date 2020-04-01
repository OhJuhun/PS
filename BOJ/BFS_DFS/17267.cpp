#include <iostream>
#include <queue>
using namespace std;

struct item{
	int x,y,L,R;
	int dis;
};

int N,M,L,R;
char arr[1001][1001];
int startX,startY;

void bfs(int x,int y){
	item it;
	it.x=x;
	it.y=y;
	it.L=L;
	it.R=R;
	queue<item> q;
	q.push(it);
	while(!q.empty()){
		item tmp=q.front();
		q.pop();
		int xx=tmp.x;
		int yy=tmp.y;
		int ll=tmp.L;
		int rr=tmp.R;
		
		while(arr[xx-1][yy]=='0' && xx-1>0){
			xx-=1;
			item tmp2;
			tmp2.x=xx;
			tmp2.y=yy;
			tmp2.R=rr;
			tmp2.L=ll;
			arr[xx][yy]='3';
			q.push(tmp2);
		}
		xx=tmp.x;
		while(arr[xx+1][yy]=='0' && xx+1<N+1){
			xx+=1;
			item tmp2;
			tmp2.x=xx;
			tmp2.y=yy;
			tmp2.R=rr;
			tmp2.L=ll;
			arr[xx][yy]='3';
			q.push(tmp2);

		}
		xx=tmp.x;
		if(arr[xx][yy-1]=='0' && yy-1>0 && ll>0){
			item tmp2;
			tmp2.x=xx;
			tmp2.y=yy-1;
			tmp2.R=rr;
			tmp2.L=ll-1;
			arr[tmp2.x][tmp2.y]='3';
			q.push(tmp2);
		}
		if(arr[xx][yy+1]=='0' && yy+1<=M && rr>0){
			item tmp2;
			tmp2.x=xx;
			tmp2.y=yy+1;
			tmp2.R=rr-1;
			tmp2.L=ll;
			arr[tmp2.x][tmp2.y]='3';
			q.push(tmp2);
		}
	}
}
void init(){
	cin>>N>>M>>L>>R;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			cin>>arr[i][j];
			if(arr[i][j]=='2'){
				startX=i;
				startY=j;
			}
		}
	}
}
void ans(){
	int cnt=1;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(arr[i][j]=='3')
				cnt++;
		}
	}
	cout<<cnt<<endl;
}

int main(){
	init();
	bfs(startX,startY);
	ans();
}

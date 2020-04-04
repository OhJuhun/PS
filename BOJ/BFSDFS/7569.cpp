#include <iostream>
#include <queue>
using namespace std;
//위로하나, 아래로하나, 좌로, 우로, 남으로,북으로
struct item{
	int x;
	int y;
	int z;
	int day;
};

int main(){
	int tomato[102][102][102];
	bool visit[102][102][102];
	queue<item> q;
	item cur,next;
	int M,N,H,cnt=0;
	cur.x=-1;
	cur.day=0;
	cin>>M>>N>>H;
	for(int i=1;i<=H;i++){
		for(int j=1;j<=N;j++){
			for(int k=1;k<=M;k++){
				cin>>tomato[i][j][k];
				visit[i][j][k]=false;
				if(tomato[i][j][k]==1){
					cur.z=i; //높이
					cur.x=j; //x축
					cur.y=k; //y축
					visit[i][j][k]=true;
					q.push(cur);
				}
				if(tomato[i][j][k]==0)
					cnt++;
			}
		}
	}
	if(cur.x==-1){
		cout<<-1<<endl;
		return 0;
	}
	while(!q.empty()){ //z<m<n 
		cur=q.front();
		q.pop();
		//방문이 안되었거나, 토마토가 없거나, 접근한 값이 경계일때 
		if(!visit[cur.z-1][cur.x][cur.y] && tomato[cur.z-1][cur.x][cur.y]!=-1 && cur.z-1>0){
			visit[cur.z-1][cur.x][cur.y]=true;
			next.x=cur.x;
			next.z=cur.z-1;
			next.y=cur.y;
			next.day=cur.day+1;
			q.push(next);
			cnt--;
		}
		if(cur.z+1<=H && !visit[cur.z+1][cur.x][cur.y] && tomato[cur.z+1][cur.x][cur.y]!=-1){
			visit[cur.z+1][cur.x][cur.y]=true;
			next.x=cur.x;
			next.y=cur.y;
			next.z=cur.z+1;
			next.day=cur.day+1;
			q.push(next);
			cnt--;
		}
		if(!visit[cur.z][cur.x-1][cur.y] && tomato[cur.z][cur.x-1][cur.y]!=-1 && cur.x-1>0){
			visit[cur.z][cur.x-1][cur.y]=true;
			next.x=cur.x-1;
			next.y=cur.y;
			next.z=cur.z;
			next.day=cur.day+1;
			q.push(next);
			cnt--;
		}
		if(cur.x+1<=N && !visit[cur.z][cur.x+1][cur.y] && tomato[cur.z][cur.x+1][cur.y]!=-1){
			visit[cur.z][cur.x+1][cur.y]=true;
			next.x=cur.x+1;
			next.y=cur.y;
			next.z=cur.z;
			next.day=cur.day+1;
			q.push(next);
			cnt--;
		}
		if(!visit[cur.z][cur.x][cur.y-1] && tomato[cur.z][cur.x][cur.y-1]!=-1 && cur.y-1>0){
			visit[cur.z][cur.x][cur.y-1]=true;
			next.y=cur.y-1;
			next.x=cur.x;
			next.z=cur.z;
			next.day=cur.day+1;
			q.push(next);
			cnt--;
		}

		if(cur.y+1<=M && !visit[cur.z][cur.x][cur.y+1] && tomato[cur.z][cur.x][cur.y+1]!=-1){
			visit[cur.z][cur.x][cur.y+1]=true;
			next.y=cur.y+1;
			next.x=cur.x;
			next.z=cur.z;
			next.day=cur.day+1;
			q.push(next);
			cnt--;
		}
	}
	if(cnt) cout<<-1<<endl;
	else cout<<cur.day<<endl;
	return 0;
}
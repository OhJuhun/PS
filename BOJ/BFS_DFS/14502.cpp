#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int safe;
int n,m;
int tmp[9][9];
int arr[9][9];
vector<int> v;
bool visit[9][9];
int vinum=0;
int st;
struct item{
	int i,j;
};

void cpy(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			tmp[i][j]=arr[i][j];
			visit[i][j]=false;
		}
	}
}
void bfs(int i,int j){
	//바이러스가 있는곳
	queue<item> q;
	item cur,next;
	cur.i=i;
	cur.j=j;
	q.push(cur);
	while(!q.empty()){
		cur=q.front();
		q.pop();
		if(cur.i-1>0 && tmp[cur.i-1][cur.j]==0 && !visit[cur.i-1][cur.j]){
			next.i=cur.i-1;
			next.j=cur.j;
			visit[next.i][next.j]=true;
			q.push(next);
			safe--;
		}
		if(cur.i+1<=n && tmp[cur.i+1][cur.j]==0 && !visit[cur.i+1][cur.j]){
			next.i=cur.i+1;
			next.j=cur.j;
			visit[next.i][next.j]=true;
			q.push(next);
			safe--;
		}
		if(cur.j-1>0 && tmp[cur.i][cur.j-1]==0 && !visit[cur.i][cur.j-1]){
			next.i=cur.i;
			next.j=cur.j-1;
			visit[next.i][next.j]=true;
			q.push(next);
			safe--;
		}	
		if(cur.j+1<=m && tmp[cur.i][cur.j+1]==0 && !visit[cur.i][cur.j+1]){
			next.i=cur.i;
			next.j=cur.j+1;
			visit[next.i][next.j]=true;
			q.push(next);
			safe--;
			
		}
	}
}

void virus(){ //2인 곳을 찾아서 0인곳으로 바이러스를 퍼트리면서 safe갯수를 센다.
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(tmp[i][j]==2) //바이러스인 곳을 찾아서 bfs
				bfs(i,j);
		}
	}
	v.push_back(safe);
	safe=st;
}

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			visit[i][j]=false;
		}
	}
}
void wall(int cnt){ 
	if(cnt==3){ //벽이 3개가 됐으면 바이러스를 뿌린 후 종료
		/*cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<tmp[i][j];
			}
			cout<<endl;
		}
		cin>>cnt;*/
		virus();
		init();
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(tmp[i][j]==0){//안전공간이면 벽을세움
				tmp[i][j]=1;
				wall(cnt+1);
				tmp[i][j]=0; //3개를 채우고 돌아오면 0으로 
			}
		}
	}
}
int main(){
	cin>>n>>m;
	safe=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>arr[i][j];
			visit[i][j]=false;
			tmp[i][j]=arr[i][j];
			if(arr[i][j]!=0)
				safe--; //벽을 세우지 않은 상태에서 안전지역수
		}
	}
	st=safe-3;
	safe-=3;
	wall(0); //벽세우기
	cout<<*max_element(v.begin(),v.end())<<endl;
}
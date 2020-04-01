#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,X,Y,C,H,K;
vector<int> v[100001]; //동맹관계
int team[100001]; //i국의 동맹대표
pair<int,int> teams[100001]; //i국의 동맹수
bool visit[100001]; //visit

bool cmp(pair<int,int> a,pair<int,int> b){
	return a.first>b.first;
}

int dfs(int s,int i,int d){
	if(visit[i]) return d;
	team[i]=s; //representive
	visit[i]=true;
	for(int j=0;j<v[i].size();j++){
		if(!visit[v[i][j]])
			d=dfs(s,v[i][j],d+1);
	}
	return d;
}
void input(){
	cin>>N>>M;
	for(int i=0;i<M;i++){
		cin>>X>>Y;
		v[X].push_back(Y);
		v[Y].push_back(X); //X와 Y가 동맹
	}
	cin>>C>>H>>K;
}

int main(){
	input();
	
	
	for(int i=1;i<=N;i++) visit[i]=false;
	teams[C].first=dfs(C,C,1);
	teams[C].second=C;
	
	teams[H].first=dfs(H,H,1);
	teams[H].second=H;
	
	for(int i=1;i<=N;i++){
		if(!visit[i] && i!=C && i!=H){
			//cout<<i<<endl;
			teams[i].first=dfs(i,i,1);
			teams[i].second=i;
		}
	} //i국의동맹수를 찾는다. except C,H
	
	
	//각팀을모두찾으
	int ans=teams[C].first; //ans=연결안된왕국의크기
	sort(teams+1,teams+N,cmp);
	
	int i=1;
	while(K--){
		if(teams[i].second==C || teams[i].second==H)
			K++;
		else
			ans+=teams[i].first;
		i++;
	}
	
	cout<<ans<<endl;
	return 0; 
}

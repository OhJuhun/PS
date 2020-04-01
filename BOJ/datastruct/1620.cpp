#include <iostream>
#include <string>
#include <map>
using namespace std;

string pocketmons[100001];
map<string, int> pocketmonsters;
int main(){
	int n,m;
	ios_base :: sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		string pocketmon;
		cin>>pocketmon;
		pocketmons[i]=pocketmon;
		pocketmonsters[pocketmon]=i;
	}

	while(m--){
		string query;
		cin>>query;
		if(query[0]<='9' && query[0]>='0')
			cout<<pocketmons[stoi(query)]<<'\n';
		else
			cout<<pocketmonsters[query]<<'\n';
	}
	return 0;
}
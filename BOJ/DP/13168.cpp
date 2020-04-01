#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 987654321;
string type_free[3]={"ITX-Saemaeul","ITX-Cheongchun","Mugunghwa"};
string type_half[2]={"S-Train","V-Train"};
int N,R;
	
map<string, int> arr;
string cities[101];
int travels[101][101];
int railro[101][101];
string route[201];
int K;
int M;


int main(){
	cin>>N>>R;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j){
				travels[i][j]=0;
				railro[i][j]=0;
			}
			else{
				travels[i][j]=INF;
				railro[i][j]=INF;
			}
		}
	}
	for(int i=0;i<N;i++){
		cin>>cities[i];
		arr.insert(make_pair(cities[i],i));
	}
	cin>>K;
	for(int i=0;i<K;i++)
		cin>>route[i];

	cin>>M;
	for(int i=0;i<M;i++){
		string type,city_from,city_to;
		int price;
		cin>>type>>city_from>>city_to>>price;
		int from=arr.find(city_from)->second;
		int to = arr.find(city_to)->second;
		if(travels[from][to]>price){
			travels[from][to]=price;
			travels[to][from]=price;
		}
		bool half=false;
		bool free=false;
		for(int j=0;j<3;j++){
			if(type_free[j]==type){
				railro[from][to]=0;
				railro[to][from]= 0;
				free=true; //-1 is free
				break;
			}
		}
		for(int j=0;j<2;j++){
			if(type_half[j]==type && !free){
				if(railro[from][to]>price/2){
					railro[from][to]=price/2;
					railro[to][from]=price/2;
					half=true;
					break;
				}
			}
		}
		if(!half && !free){
			if(railro[from][to]>price){
				railro[from][to]=price;
				railro[to][from]=price;
			}
		}
	}


		for(int k=0;k<N;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				travels[i][j]=min(travels[i][j],travels[i][k]+travels[k][j]);
				railro[i][j]=min(railro[i][j],railro[i][k]+railro[k][j]);
			}
		}
	}
	long long ra=0;
	long long tr=R;
	for(int i=0;i<K-1;i++){
			ra+=travels[arr.find(route[i])->second][arr.find(route[i+1])->second];
			tr+=railro[arr.find(route[i])->second][arr.find(route[i+1])->second];
	}
	if(tr>=ra)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;
	return 0;
}

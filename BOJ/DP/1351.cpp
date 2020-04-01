#include <stdio.h>
#include <map>
using namespace std;

long long p,q;
map<long long, long long> cache;

long long dp(long long n){
	if(n==0) return 1;
	else if(cache[n]!=0)
		return cache[n];
	else{
		return cache[n]=dp(n/p)+dp(n/q);
	}
}
int main(){
	long long n;
	scanf("%lld%lld%lld",&n,&p,&q);
	//최대 인덱스 : 5000000
	cache[0]=1;
	cache[1]=2;
	printf("%lld\n",dp(n));
}
#include <iostream>
#include <algorithm>

using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
#define INF 987654321;

int arr[7];
int m,n,x,y;

int gcd(int a,int b){
    return b== 0 ? a : gcd(b,a%b);
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}
int solve(){
    int year = x; //처음엔 x년
    int ans = year%n;
    int MAX = lcm(m,n);
    bool flag = false;
    while(MAX>=year){
        int tmp = ans == 0 ? n : ans;
        if(tmp == y){
            flag = true;
            break;
        }
        year+=m;
        ans=year%n;
    }
    return flag ? year : -1;

}
void input(){
    cin>>m>>n>>x>>y;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        input();
        cout<<solve()<<'\n';
    }
    return 0;
}g
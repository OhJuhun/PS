#include <iostream>
#include <algorithm>

using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0),cout.tie(0)
#define INF 987654321;
int arr[101][101];
int n,m;

void fw(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==k || k==j || k == i  || i == j) continue;
                arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
            }
        }
    }
}
void input(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) arr[i][j]=INF;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        arr[x][y]=min(arr[x][y],z);
    }
}
int main(){
    input();
    fw();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<( arr[i][j] == 987654321 ? 0 : arr[i][j])<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
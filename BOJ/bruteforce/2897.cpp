#include <iostream>
#include <string>

using namespace std;

#define fastio ios_base::sync_with_stdio,cin.tie(0), cout.tie(0)

int R,C;
char arr[50][50];
int answer[5];

int dir[4][2]= {{0,0},{1,0},{0,1},{1,1}};
void solve(){
    for(int i=0;i<R-1;i++){
        for(int j=0;j<C-1;j++){
            int brokenCar = 0;
            bool flag = true;
            for(int k=0;k<4;k++){
                int ni=i+dir[k][0];
                int nj=j+dir[k][1];
                if(arr[ni][nj]=='#'){
                     flag= false;
                     break;
                }
                else if(arr[ni][nj]=='X') brokenCar++;
            }
            if(flag) answer[brokenCar]++;
        }
    }
}
void input(){
    cin>>R>>C;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>arr[i][j];
        }
    }
}
int main(){
    fastio;
    input();
    solve();
    for(int i=0;i<5;i++) cout<<answer[i]<<'\n';
}
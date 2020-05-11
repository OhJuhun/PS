
#include <iostream>

using namespace std;


struct robotinfo{
    int r,c,d;

};
int A,B;
//가로 세로
int N,M;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}}; //북 동 남 서
robotinfo robots[101];

int arr[101][101];

void turnLeft(int n){
    switch(robots[n].d){
        case 0:
            robots[n].d=3;
        break;
        case 1:
        robots[n].d=0;
        break;
        case 2:
        robots[n].d=1;
        break;
        case 3:
        robots[n].d=2;
        break;
    }
}
void turnRight(int n){
    switch(robots[n].d){
        case 0:
        robots[n].d=1;
        break;
        case 1:
        robots[n].d=2;
        break;
        case 2:
        robots[n].d=3;
        break;
        case 3:
        robots[n].d=0;
        break;
    }
}
void input(){
    cin>>A>>B>>N>>M;
    for(int i=1;i<=N;i++){
        int r,c;
        char d;
        cin>>c>>r>>d;
        robots[i].r=r;
        robots[i].c=c;
        if(d=='N'){
            robots[i].d=0;
        }
        else if(d=='E'){
            robots[i].d=1;
        }
        else if(d=='S'){
            robots[i].d=2;
        }
        else{
            robots[i].d=3;
        }
        arr[r][c]=i; //r,c에 i번 로봇
    }
}
int main(){
    input();
    char error='O';
    int cr[2];
    for(int i=0;i<M;i++){
        int n,rec;
        char cmd;
        cin>>n>>cmd>>rec;
        if(error!='O') continue;
        while(rec--){
            if(cmd=='L'){
                turnLeft(n);
            }
            else if(cmd=='R'){
                turnRight(n);
            }
            else{
                int nextr= robots[n].r+dir[robots[n].d][0];
                int nextc=robots[n].c+dir[robots[n].d][1]; //다음 위치
                if(nextr>B || nextc>A || nextr<1 || nextc<1){
                    error = 'W';
                    cr[0]=n;
                    break;
                }
                if(arr[nextr][nextc]!=0){
                    error='C';
                    cr[0]=n;
                    cr[1]=arr[nextr][nextc];
                    break;
                }
                //부딪히거나 밖에 나가는 경우가 아닐 때
                arr[robots[n].r][robots[n].c]=0;
                robots[n].r=nextr;
                robots[n].c=nextc;
                arr[nextr][nextc]=n;
            }
        }
    }
    if(error=='O'){
        cout<<"OK\n";
    }
    else if(error=='C'){
        cout<<"Robot "<<cr[0]<<" crashes into robot "<<cr[1]<<'\n';
    }
    else{
        cout<<"Robot "<<cr[0]<<" crashes into the wall\n";
    }
}
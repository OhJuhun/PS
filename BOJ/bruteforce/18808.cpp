#include <iostream>
#include <cstring>
using namespace std;

#define PREPROCESS ios_base::sync_with_stdio,cin.tie(0),cout.tie(0);

bool notebook[40][40];
int N,M,K;


int r,c;
bool sticker[10][10];
bool stick(int sr,int sc,bool sticker[10][10]){
    if(sr+r>N || sc+c>M) return false;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(notebook[sr+i][sc+j] ==1 && sticker[i][j]==1 ) return false;
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            notebook[sr+i][sc+j] += sticker[i][j];
        }
    }
    return true;
}

void turn(){
    bool tmp[10][10];
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            tmp[i][j]=sticker[r-j-1][i];
        }
    }
    memset(sticker,0,sizeof(sticker));
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            sticker[i][j]=tmp[i][j];
        }
    }
    int tmpr=c;
    c=r;
    r=tmpr;
}
void input(){
    cin>>N>>M>>K;
    for(int i=0;i<K;i++){
        cin>>r>>c;
        memset(sticker,0,sizeof(sticker));
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                cin>>sticker[j][k];
            }
        }
        bool sticked=false;
        for(int j=0;j<4 && !sticked;j++){
            for(int k=0;k<N && !sticked;k++){
                for(int l=0;l<M && !sticked;l++){
                    sticked = stick(k,l,sticker);
                }
            }
            if(!sticked) turn();
        }
    }
}

int solve(){
    int ret = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(notebook[i][j]) ret++;
        }
    }
    return ret;
}
int main(){
    PREPROCESS;
    input();
    cout<<solve()<<'\n';
    return 0;
}
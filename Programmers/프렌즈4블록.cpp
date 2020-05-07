#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

bool isBoom(int r,int c,vector<string> board){
    char target= board[r][c];
    for(int i=r;i<r+2;i++){
        for(int j=c;j<c+2;j++)
            if(board[i][j]!=target) return false;
    }
    return true;
}
int boom(set<pair<int,int>> s,vector<string>& board){
    for(pair<int,int> p : s){
        board[p.first][p.second]='0';
    }
    return s.size();
}
vector<string> down(vector<string> board,int m,int n){
    for(int j=0;j<n;j++){
        int cnt=0;
        for(int i=m-1;i>=0;i--){
            if(board[i][j]=='0') cnt++;
            else if(cnt!=0){
                board[i+cnt][j]=board[i][j];
                board[i][j]='0';
            }
        }
    }
    return board;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    while(true){
        bool flag=false;
        set<pair<int,int>> cand;
        for(int i=0;i<m-1;i++){
            for(int j=0;j<n-1;j++){
                if(board[i][j]!='0' &&isBoom(i,j,board)){
                    cand.insert({i,j});
                    cand.insert({i+1,j});
                    cand.insert({i,j+1});
                    cand.insert({i+1,j+1});
                    flag = true;
                }
            }
        }
      
        if(flag){
            answer += boom(cand,board);
            board = down(board,m,n);
        }
        else break;
    }
    return answer;
}
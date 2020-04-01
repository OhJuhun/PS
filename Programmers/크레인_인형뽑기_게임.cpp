#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int idx[101];
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int rsize = board.size();
    int csize = board[0].size();
    stack<int> basket;
    for(int i=0;i<csize;i++){
        for(int j=0;j<rsize;j++){
            if(board[j][i]){
                idx[i]=j;
                break;
            }
        }
    }
    for(int move : moves){
        if(idx[move-1]>=rsize) continue;
        if(board[idx[move-1]][move-1]){
            if(basket.empty()){
                basket.push(board[idx[move-1]][move-1]);
            }
            else{
                if(basket.top()==board[idx[move-1]][move-1]){
                    answer+=2;
                    basket.pop();
                }
                else{
                    basket.push(board[idx[move-1]][move-1]);
                }
            }
        }
                idx[move-1]++;
    }
    while(!basket.empty()){
        cout<<basket.top()<<" ";
        basket.pop();
    }
    return answer;
}
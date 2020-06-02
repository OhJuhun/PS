#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> go(int x,int y, bool arr[8][8],int d[2]){
        vector<int> ret;
        while(true){
            x+=d[0];
            y+=d[1];
            if(x<0 ||y<0 || x>=8 || y>=8) break;
            if(arr[x][y]==1){
                ret.push_back(x);
                ret.push_back(y);
                break;
            }
        }
        
        return ret;
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        const int x = king[0];
        const int y = king[1];
        vector<vector<int>> answer;
        bool arr[8][8];
        memset(arr,0,sizeof(arr));
        for(vector<int> queen:queens){
            arr[queen[0]][queen[1]]=true;
        }
        int dir[8][2]= {{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        for(int i=0;i<8;i++){
            vector<int> tmp = go(x,y,arr,dir[i]);
            if(!tmp.empty()) answer.push_back(tmp);
        }
        return answer;
    }
};
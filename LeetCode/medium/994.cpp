class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        queue<int> time;
        int N = grid.size();
        int M = grid[0].size();
        int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==2) q.push({i,j}),time.push(0);
                
            }
        }
        while(!q.empty()){
            pair<int,int> cur = q.front();
            int t = time.front();
            time.pop();
            q.pop();
            ans = max(t,ans);
            for(int i=0;i<4;i++){
                pair<int,int> next = {cur.first+dir[i][0],cur.second+dir[i][1]};
                if(next.first>=N || next.second>=M || next.first<0 || next.second<0 || grid[next.first][next.second]!=1) continue;
                grid[next.first][next.second]=2;
                q.push(next);
                time.push(t+1);
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++) if(grid[i][j]==1) return -1;
        }
        return ans;
    }
};
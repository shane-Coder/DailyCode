class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> v(n,vector<int>(m,-1));
        queue<vector<int>> q;
        q.push({0,0,0,k});
        while(!q.empty()){
            auto it = q.front();
            int x = it[0], y = it[1];
            q.pop();
            if(x<0 or y<0 or x>=n or y>=m)
                continue;
            if(x==n-1 and y==m-1)
                return it[2];
            if(grid[x][y]==1){
                if(it[3]>0)
                    it[3]--;
                else 
                    continue;
            }
            if(v[x][y]!=-1 and v[x][y]>=it[3])
                 continue;
            v[x][y] = it[3];
            q.push({x+1, y, it[2]+1, it[3]});
            q.push({x-1, y, it[2]+1, it[3]});
            q.push({x, y+1, it[2]+1, it[3]});
            q.push({x, y-1, it[2]+1, it[3]});
        }
        return -1;
    }
};
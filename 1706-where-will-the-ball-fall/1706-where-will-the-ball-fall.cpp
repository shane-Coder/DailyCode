class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<int> res(m,0);
        vector<vector<int>> dp(n+1, vector<int>(m,0));
        for(int i=int(n); i>=0; i--){
            for(int j=0; j<m; j++){
                if(i==n){
                    dp[i][j] = j;
                    continue;
                }
                int col = j+grid[i][j];
                if(col<0 or col>m-1 || grid[i][j]!=grid[i][col])
                    dp[i][j] = -1;
                else
                    dp[i][j] = dp[i+1][col];
                if(i==0)
                    res[j] = dp[i][j];
            }
        }
        return res;
    }
};
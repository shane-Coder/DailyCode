class Solution {
    
    public int solve(int[][] dp, int low, int high){
        if(low>=high)
            return 0;
        if(dp[low][high]!=0)
            return dp[low][high];
        int res = Integer.MAX_VALUE;
        for(int i=low; i<=high; i++){
            int temp = i + Math.max(solve(dp, low, i-1), solve(dp, i+1, high));
            res = Math.min(res,temp);
        }
        dp[low][high] = res;
        return res;
    }
    
    public int getMoneyAmount(int n) {
        int[][] dp = new int [n+1][n+1];
        return solve(dp, 1, n);
    }
    
}
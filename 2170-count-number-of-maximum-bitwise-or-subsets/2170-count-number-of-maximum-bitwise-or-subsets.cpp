class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ct=0;
        vector<int>dp(1<<17,0);
        dp[0] = 1;
        for(auto it:nums){
            for(int i=ct; i>=0; i--)
                dp[i|it] += dp[i];
            ct = ct|it;
        }
        return dp[ct];
    }
};
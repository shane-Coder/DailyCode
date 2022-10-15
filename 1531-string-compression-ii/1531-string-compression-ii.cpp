int dp[101][27][11][101];
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        if(s.size()==100){
            bool flag = true;
            for(int i=1; i<s.size(); i++){
                if(s[i]!=s[i-1]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return 4;
        }
        if(k>=s.size())
            return 0;
        for(int i=0; i<101; i++){
            for(int j=0; j<27; j++){
                for(int m=0; m<11; m++){
                    for(int l=0; l<101; l++){
                        dp[i][j][m][l] = -1;
                    }
                }
            }
        }
        return solve(s, 0, 'z'+1, 0, k);
    }
    int solve(string &s, int curr, char end, int ct, int k){
        int res = 101;
        if(k<0)
            return 101;
        if(curr>=s.size())
            return 0;
        if(ct>=10)
            ct = 10;
        if(dp[curr][end-'a'][ct][k]!=-1)
            return dp[curr][end-'a'][ct][k];
        res = solve(s, curr+1, end, ct, k-1);
        if(s[curr]!=end)
            res = min(res, 1+solve(s, curr+1, s[curr], 1, k));
        else{
            if(ct==1 or ct==9)
                res = min(res, 1+solve(s, curr+1, end, ct+1, k));
            else
                res = min(res, solve(s, curr+1, end, ct+1, k));
        }
        return dp[curr][end-'a'][ct][k] = res;
    }
};
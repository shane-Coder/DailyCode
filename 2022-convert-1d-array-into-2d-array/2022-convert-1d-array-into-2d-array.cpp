class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int r=original.size();
        if(r!=m*n)
            return {};
        vector<vector<int>> res(m,vector<int>(n));
        for(int i=0; i<r; i++){
            res[i/n][i%n] = original[i];
        }
        return res;
    }
};
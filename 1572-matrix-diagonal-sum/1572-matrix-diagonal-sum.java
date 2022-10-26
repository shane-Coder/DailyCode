class Solution {
    public int diagonalSum(int[][] mat) {
        int n = mat.length, res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    res += mat[i][j];
                }
                if(i+j==n-1){
                    res += mat[i][j];
                }
            }
        }
        if(n%2==0){
            return res;
        }
        else{
            int m = (n-1)/2;
            res -= mat[m][m];
            return res;
        }
    }
}
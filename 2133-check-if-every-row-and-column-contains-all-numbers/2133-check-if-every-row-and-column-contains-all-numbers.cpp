class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<set<int>> row(n), col(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int value = matrix[i][j];
                if(row[i].count(value) or col[j].count(value))
                    return false;
                row[i].insert(value);
                col[j].insert(value);
            }
        }
        return true;
    }
};
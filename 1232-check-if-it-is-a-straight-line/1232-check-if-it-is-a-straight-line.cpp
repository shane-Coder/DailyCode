class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=2)
            return true;
        int x, y, n=coordinates.size();
        y = coordinates[1][1] - coordinates[0][1];
        x = coordinates[1][0] - coordinates[0][0];
        for(int i=2; i<n; i++){
            if(x*(coordinates[i][1]-coordinates[0][1]) != y*(coordinates[i][0]-coordinates[0][0]))
                return false;
        }
        return true;
    }
};
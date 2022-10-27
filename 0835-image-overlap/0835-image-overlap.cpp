class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> a,b;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(img1[i][j]==1)
                    a.push_back({i,j});
                if(img2[i][j]==1)
                    b.push_back({i,j});
            }
        }
        int res=0;
        map<pair<int,int>,int> mp;
        for(auto [i,j]:a){
            for(auto [k,l]:b){
                mp[{i-k,j-l}]++;
                res = max(res, mp[{i-k,j-l}]);
            }
        }
        return res;
    }
};
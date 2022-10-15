class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res=0, m=0, c=0;
        int n = neededTime.size();
        for(int i=0; i<n; i++){
            if(i>0 and colors[i]!=colors[i-1]){
                res += (c-m);
                c = 0;
                m = 0;
            }
            c += neededTime[i];
            m = max(m, neededTime[i]);
        }
        res += (c-m);
        return res;
    }
};
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> index(plantTime.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int i, int j)
        {return growTime[i]>growTime[j];});
        int res=0, curr=0;
        for(auto it:index){
            curr += plantTime[it];
            res = max(res, curr+growTime[it]);
        }
        return res;
    }
};
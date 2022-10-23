class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> v(nums.size()+1,0);
        for(auto it:nums)
            v[it]++;
        int n,m;
        for(int i=0; i<v.size(); i++){
            if(v[i]==0)
                n = i;
            if(v[i]==2)
                m = i;
        }
        return {m,n};
    }
};
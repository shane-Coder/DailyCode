class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(), ct=0, take=0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0; i<n; i++){
            take += nums[i];
            if(mp.find(take-k)!=mp.end()){
                ct += mp[take-k];
            }
            mp[take] += 1;
        }
        return ct;
    }
};
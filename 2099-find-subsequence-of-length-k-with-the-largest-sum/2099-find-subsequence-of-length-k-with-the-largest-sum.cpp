class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> res, temp=nums;
        unordered_map<int,int> mp;
        sort(nums.begin(), nums.end());
        for(int i=0; i<k; i++){
            mp[nums[nums.size()-1-i]]++;
        }
        for(auto it:temp){
            if(mp[it]-- > 0)
                res.push_back(it);
        }
        return res;
    }
};
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp{{0,0}};
        int take = 0;
        for(int i=0; i<nums.size(); i++){
            take += nums[i];
            if(!mp.count(take%k))
                mp[take%k] = i+1;
            else if(mp[take%k]<i)
                return true;
        }
        return false;
    }
};
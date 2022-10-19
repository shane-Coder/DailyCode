class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int low=0, high=0;
        int start=0, end=0;
        int res=0;
        
        for(int i=0; i<nums.size(); ++i){
            
            low += nums[i];
            while(start<i && low>goal)
                low -= nums[start++];
            
            high += nums[i];
            while(end<i && (high>goal || high==goal && nums[end]==0))
                high -= nums[end++];
            
            if(low==goal)
                res += end-start+1;
        }
        
        return res;
    }
};
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int size=nums.size();
        vector<int>right(size);
        right[size-1] = nums[size-1];
        for(int i=size-2; i>=0; i--){
            right[i] = max(right[i+1], nums[i]);
        }
        int low=0, high=0;
        int maxi=0;
        while(high<size){
            while(low<high && nums[low]>right[high])    low++;
            maxi = max(maxi, high-low);
            high++;
        }
        return maxi;
    }
};
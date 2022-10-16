class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int n=nums.size();
        k = k%n;
        if(n<2 or k<1)
            return ;
        
        for(int i=n-k; i<n; i++)
            temp.push_back(nums[i]);
        
        for(int i=0; i<n-k; i++)
            temp.push_back(nums[i]);
        
        nums = temp;
    }
};
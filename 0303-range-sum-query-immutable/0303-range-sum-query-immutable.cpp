class NumArray {
public:
    vector<int> res;
    NumArray(vector<int>& nums) {
        res.push_back(0);
        for(int i=0; i<nums.size(); i++)
            res.push_back(res.back() + nums[i]);
    }
    
    int sumRange(int left, int right) {
        return res[right+1]-res[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
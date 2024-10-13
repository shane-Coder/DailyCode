class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>>merge;
        for(int i=0; i<nums.size(); i++){
            for(auto it:nums[i]){
                merge.push_back({it,i});
            }
        }
        sort(merge.begin(), merge.end());
        unordered_map<int,int>mp;
        int left=0, ct=0;
        int start=0, end=INT_MAX;
        for(int right=0; right<merge.size(); right++){
            mp[merge[right].second]++;
            if(mp[merge[right].second]==1)  ct++;
            while(ct==nums.size()){
                int curr = merge[right].first-merge[left].first;
                if(curr < end-start){
                    start = merge[left].first;
                    end = merge[right].first;
                }
                mp[merge[left].second]--;
                if(mp[merge[left].second]==0)   ct--;
                left++;
            }
        }
        return {start,end};
    }
};
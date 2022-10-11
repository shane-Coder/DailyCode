#include<bits/stdc++.h>
class Solution {
public:
    
    static bool cmp(pair<int,int>& ar, pair<int,int>& br){
        if(ar.second==br.second)
            return ar.first>br.first;
        else
            return ar.second<br.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) {
        if(nums.size()==1)
            return nums;
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        vector<pair<int,int>> ar;
        for(auto it:mp){
            ar.push_back(it);
        }
        sort(ar.begin(), ar.end(), cmp);
        vector<int> res;
        for(auto it:ar){
            int i = it.second, e = it.first;
            while(i>0){
                res.push_back(e);
                i--;
            }
        }
        return res;
    }
};
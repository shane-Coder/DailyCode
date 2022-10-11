class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int a=0, b=0;
        for(auto it:mp){
            if(it.second%2==0){
                a += (it.second/2);
            }
            else{
                a += ((it.second-1)/2);
                b += 1;
            }
        }
        return {a,b};
    }
};
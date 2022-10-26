class Solution {
public:
    string kthDistinct(vector<string>& ar, int k) {
        unordered_map<string,int> mp;
        for(auto it:ar)
            ++mp[it];
        
        for(auto it:ar){
            if(mp[it]==1 and (--k)==0){
                return it;
            }
        }
        return "";
    }
};
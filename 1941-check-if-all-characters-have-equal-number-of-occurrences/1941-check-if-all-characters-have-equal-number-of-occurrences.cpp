class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int> mp;
        for(auto ch:s){
            mp[ch]++;
        }
        int ct = mp[s[0]];
        for(auto it:mp){
            if(ct!=it.second)
                return false;
        }
        return true;
    }
};
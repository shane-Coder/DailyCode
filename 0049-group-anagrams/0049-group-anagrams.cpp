class Solution {
    
private:
    string helper(string s){
        int n = s.length(), counter[26] = {0};
        for(auto ch:s)
            counter[ch-'a']++;
        string temp;
        for(int i=0; i<26; i++)
            temp += string(counter[i], i+'a');
        return temp;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(auto s:strs)
            mp[helper(s)].push_back(s);
        vector<vector<string>> res;
        for(auto i:mp)
            res.push_back(i.second);
        return res;
    }
};
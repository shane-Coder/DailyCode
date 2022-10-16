class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res="", ans="";
        for(auto s:word1)
            res += s;
        for(auto v:word2)
            ans += v;
        return ans==res;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it:t){
            mp[it]++;
        }
        char ch;
        for(auto it:mp){
            if(it.second%2==1){
                ch = it.first;
            }
        }
        return ch;
    }
};
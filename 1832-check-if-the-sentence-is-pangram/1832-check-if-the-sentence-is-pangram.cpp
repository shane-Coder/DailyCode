class Solution {
public:
    bool checkIfPangram(string sentence) {
        array<bool,26> flag{};
        for(auto ch:sentence){
            flag[ch-'a'] = true;
        }
        for(auto it:flag){
            if(it==false)
                return false;
        }
        return true;
    }
};
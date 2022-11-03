class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        constexpr int letter = 26;
        vector count(letter, vector<int>(letter));
        for(const string& s:words)
            count[s[0]-'a'][s[1]-'a']++;
        int res=0;
        bool flag = false;
        for(int i=0; i<letter; i++){
            if(count[i][i]%2==0)
                res += count[i][i];
            else{
                res += count[i][i]-1;
                flag = true;
            }
            for(int j=i+1; j<letter; j++){
                res += 2*min(count[i][j], count[j][i]);
            }
        }
        if(flag)
            res++;
        return res*2;
    }
};
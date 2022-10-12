class Solution {
public:
    int numSub(string s) {
        long long res=0;
        for(int i=0; i<s.size(); i++){
            long long ct=0;
            while(i<s.size() and s[i]=='1'){
                ct++;
                i++;
            }
            res += ct*(ct+1)/2;
        }
        return res%1000000007;
    }
};
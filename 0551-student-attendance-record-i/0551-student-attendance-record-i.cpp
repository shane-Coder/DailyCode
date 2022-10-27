class Solution {
public:
    bool checkRecord(string s) {
        int i=0, n=s.length(), ct=0;
        while(i<n){
            if(s[i]=='L' and s[i+1]=='L' and s[i+2]=='L')
                return false;
            if(s[i]=='A')
                ct++;
            if(ct==2)
                return false;
            i++;
        }
        return true;
    }
};
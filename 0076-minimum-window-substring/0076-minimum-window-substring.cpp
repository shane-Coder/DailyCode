class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()==0 or t.length()==0)
            return "";
        
        map<char,int> mp;
        for(int i=0; i<t.length(); i++){
            mp[t[i]]++;
        }
        int n = mp.size();
        string res;
        int l=0, r=0, d=INT_MAX;
        while(r<s.length()){
            if(mp.find(s[r])!=mp.end()){
                mp[s[r]]--;
                if(mp[s[r]]==0){
                    n--;
                }
            }
            while(n==0){
                if(d>r-l+1){
                    d = min(d,r-l+1);
                    res = s.substr(l,r-l+1);
                }
                if(mp.find(s[l])!=mp.end()){
                    mp[s[l]]++;
                    if(mp[s[l]]==1){
                        n++;
                    }
                }
                l++;
            }
            r++;
        }
        return res;
    }
};
class Solution {
public:
    
    int solve(vector<string>&ar, string str, int index){
        unordered_set<char> s(str.begin(), str.end());
        if(s.size() != ((int)str.length()))
            return 0;
        
        int res = str.length();
        for(int i=index; i<ar.size(); i++)
            res = max(res, solve(ar, str+ar[i], i+1));
        return res;    
    }
    
    int maxLength(vector<string>& ar) {
        string str = "";
        int index = 0;
        int res = solve(ar, str, index);
        return res;
    }
};
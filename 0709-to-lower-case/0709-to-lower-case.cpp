class Solution {
public:
    string toLowerCase(string s) {
        string res="";
        for(auto ch:s){
            if(ch>='A' and ch<='Z')
                res += (ch+32);
            else
                res += ch;
        }
        return res;
    }
};
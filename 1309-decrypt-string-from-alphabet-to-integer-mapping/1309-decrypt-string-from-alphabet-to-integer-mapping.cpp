class Solution {
public:
    string freqAlphabets(string s) {
        string res="";
        int i=s.length()-1, k;
        while(i>=0){
            if(s[i]=='#'){
                k = stoi(s.substr(i-2,2));
                i = i-3;
            }
            else{
                k = (s[i]-'0');
                i = i-1;
            }
            res = char(96+k)+res;
        }
        return res;
    }
};
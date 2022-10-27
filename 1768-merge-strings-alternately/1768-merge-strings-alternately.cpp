class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0, j=0;
        string res = "";
        while(i<word1.size() and j<word2.size()){
            res += word1[i];
            res += word2[j];
            i++; j++;
        }
        if(i==word1.size()){
            while(j<word2.size()){
                res += word2[j]; j++;}
        }
        if(j==word2.size()){
            while(i<word1.size()){
                res += word1[i]; i++;}
        }
        return res;
    }
};
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string word = countAndSay(n-1);
        string say = "";
        int ct = 1;
        for(int i=1; i<word.size(); i++){
            if(word[i]==word[i-1]){
                ct++;
            }
            else{
                say += to_string(ct) + word[i-1];
                ct = 1;
            }
        }
        say += to_string(ct) + word[word.length()-1];
        return say;
    }
};
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream word1(sentence1), word2(sentence2);
        string letter;
        vector<string> s1w, s2w;
        while(word1 >> letter)    s1w.push_back(letter);
        while(word2 >> letter)    s2w.push_back(letter);
        int start=0, end1=s1w.size()-1, end2=s2w.size()-1;
        if(s1w.size()>s2w.size())   return areSentencesSimilar(sentence2, sentence1);
        while(start<s1w.size() && s1w[start]==s2w[start])   ++start;
        while(end1>=0 && s1w[end1]==s2w[end2]){
            --end1;
            --end2;
        }
        return end1<start;
    }
};
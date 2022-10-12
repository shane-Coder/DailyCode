class Solution {
public:
    int countVowelSubstrings(string word) {
        int res=0, n=word.size();
        unordered_set<char> vowel {'a', 'e', 'i', 'o', 'u'};
        for(int i=0; i<n; i++){
            unordered_set<char> ch;
            for(int j=i; j<n; j++){
                ch.insert(word[j]);
                if(ch==vowel)
                    res++;
            }
        }
        return res;
    }
};
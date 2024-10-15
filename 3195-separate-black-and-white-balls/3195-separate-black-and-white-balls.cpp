class Solution {
public:
    long long minimumSteps(string s) {
        long long swap = 0;
        int ct = 0;

        // Iterate through each ball (character) in the string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                // Swap with all black balls to its left
                swap += (long long)ct;
            } else {
                // Increment the count
                ct++;
            }
        }

        return swap;
    }
};
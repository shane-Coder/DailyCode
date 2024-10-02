class Solution {
public:
    string losingPlayer(int x, int y) {
        int m = min(x, y/4);
        if(m%2==1)
            return "Alice";
        else
            return "Bob";
    }
};
class Solution {
public:
    char findKthBit(int n, int k) {
        int pos = k&(-k);
        bool flag = ((k/pos)>>1&1)==1;
        bool org = (k&1)==0;
        if(flag) 
            return org?'0':'1';
        else
            return org?'1':'0';
    }
};
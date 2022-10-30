#include<bits/stdc++.h>
class Solution {
public:
    static bool compare(int &a, int &b){
        int c,d;
        c = __builtin_popcount(a);
        d = __builtin_popcount(b);
        if(c==d)
            return a<=b;
        return c<d;
    }
    vector<int> sortByBits(vector<int>& ar) {
        sort(ar.begin(), ar.end(), compare);
        return ar;
    }
};
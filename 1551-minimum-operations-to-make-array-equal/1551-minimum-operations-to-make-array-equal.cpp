class Solution {
public:
    int minOperations(int n) {
        int res = 0;
        vector<int> v;
        int k=1;
        while(k<=n){
            v.push_back(k);
            k += 2;
        }
        for(auto it:v){
            res += (n-it);
        }
        return res;
    }
};
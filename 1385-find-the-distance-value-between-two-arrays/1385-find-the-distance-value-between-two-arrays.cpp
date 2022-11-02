class Solution {
public:
    
    bool check(int val, vector<int>&num, int diff){
        int start=0, end=num.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(abs(num[mid]-val)<=diff)
                return false;
            else if(num[mid]<val)
                start = mid+1;
            else
                end = mid-1;
        }
        return true;
    }
    
    int findTheDistanceValue(vector<int>& ar, vector<int>& br, int d) {
        sort(br.begin(), br.end());
        int ct=0;
        for(auto it:ar){
            if(check(it, br, d))
                ct++;
        }
        return ct;
    }
};
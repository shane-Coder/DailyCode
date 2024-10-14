class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int res=0;
        priority_queue<int>pq;
        for(auto it:nums){
            pq.push(it);
        }
        while(k--){
            int ele = pq.top();
            res += ele;
            pq.pop();
            pq.push(ceil(ele/3.0));
        }
        return res;
    }
};
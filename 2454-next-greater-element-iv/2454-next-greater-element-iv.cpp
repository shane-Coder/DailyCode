class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ar(n,vector<int>(0));
        stack<int> st;
        for(int i=0; i<n; i++){
            while(st.size() and nums[st.top()]<nums[i]){
                ar[i].push_back(st.top());
                st.pop();
            }
            st.push(i);
        }
        priority_queue<vector<int>> pq;
        vector<int> res(n,-1);
        for(int i=0; i<n; i++){
            while(pq.size() and -pq.top()[0]<nums[i]){
                res[pq.top()[1]] = nums[i];
                pq.pop();
            }
            for(auto it:ar[i]){
                pq.push({-nums[it],it});
            }
        }
        return res;
    }
};
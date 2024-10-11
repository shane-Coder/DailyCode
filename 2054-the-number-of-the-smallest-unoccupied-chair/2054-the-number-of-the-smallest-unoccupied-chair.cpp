class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>leave;
        int target = times[targetFriend][0];
        sort(times.begin(), times.end());
        int next=0;
        set<int>available;
        for(auto it:times){
            int start=it[0];
            int end=it[1];
            while(!leave.empty() && leave.top().first<=start){
                available.insert(leave.top().second);
                leave.pop();
            }
            int curr;
            if(!available.empty()){
                curr = *available.begin();
                available.erase(available.begin());
            }    
            else{
                curr = next++;
            }
            leave.push({end,curr});
            if(start==target)   return curr;
        }
        return 0;
    }
};
class Solution {
private:
    struct helper{
        bool operator()(const pair<int, string> &a, const pair<int, string> &b){
            if(a.first!=b.first){
                return a.first>b.first;
            }
            else{
                return a.second<b.second;
            }
        }
    };
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto s:words){
            mp[s]++;
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>, helper> pq;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            pq.push(make_pair(it->second, it->first));
            if(pq.size()>k)
                pq.pop();
        }
        vector<string> res;
        while(!pq.empty()){
            res.insert(res.begin(), pq.top().second);
            pq.pop();
        }
        return res;
    }
};
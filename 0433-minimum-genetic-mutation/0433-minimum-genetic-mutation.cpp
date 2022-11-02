class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> s;
        q.push(start);
        s.insert(start);
        int d=0;
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                string v = q.front();
                q.pop();
                if(v==end)
                    return d;
                for(char c:"ACGT"){
                    for(int j=0; j<v.size(); j++){
                        string p = v;
                        p[j] = c;
                        if(!s.count(p) && find(bank.begin(), bank.end(), p) != bank.end()){
                            q.push(p);
                            s.insert(p);
                        }
                    }
                }
            }
            d++;
        }
        return -1;
    }
};
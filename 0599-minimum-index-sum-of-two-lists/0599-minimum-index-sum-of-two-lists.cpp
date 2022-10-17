#include<bits/stdc++.h>
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> mp;
        for(int i=0; i<list1.size(); i++)
            mp.insert({list1[i],i});
        vector<string> res;
        int m=INT_MAX, cur;
        for(int j=0; j<list2.size() and j<=m; j++){
            if(mp.find(list2[j])!=mp.end()){
                cur = j+mp[list2[j]];
                if(cur<m){
                    res.clear();
                    res.push_back(list2[j]);
                    m = cur;
                }
                else if(m==cur){
                    res.push_back(list2[j]);
                }
            }
        }
        return res;
    }
};
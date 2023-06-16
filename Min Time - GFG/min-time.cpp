//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    #define ll long long
    unordered_map<ll,pair<ll,ll>>mp;
    vector<int>take;
    ll dp[100004][3];
  public:
    ll solve(int x, int y){
        ll pos=0;
        if(y==0)
            pos = mp[take[x-1]].first;
        else if(y==1)
            pos = mp[take[x-1]].second;
        if(x==take.size())
            return abs(pos);
        if(dp[x][y]!=-1)
            return dp[x][y];
        ll res=1e18, d=abs(mp[take[x]].second-mp[take[x]].first);
        res = min(res, d+abs(mp[take[x]].first-pos)+solve(x+1,1));
        res = min(res, d+abs(mp[take[x]].second-pos)+solve(x+1,0));
        return dp[x][y]=res;
    }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        // code here
        for(int i=0; i<n; i++){
            int l=locations[i], t=types[i];
            if(mp.count(t)){
                int x = mp[t].first, y=mp[t].second;
                x = min(x,l), y=max(y,l);
                mp[t] = {x,y};
            }
            else
                mp[t] = {l,l};
        }
        for(auto it:mp) take.push_back(it.first);
        sort(take.begin(), take.end());
        memset(dp, -1, sizeof(dp));
        return solve(0,2);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
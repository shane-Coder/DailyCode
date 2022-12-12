//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void solve(int start, vector<int>& dis, vector<int>& low, vector<bool>& vis, int end, vector<int> adj[], int &time, vector<int>& ar){
        vis[start] = true;
        dis[start] = low[start] = time++;
        int child = 0;
        for(auto it:adj[start]){
            if(it==end) continue;
            if(vis[it]==false){
                solve(it, dis, low, vis, start, adj, time, ar);
                low[start] = min(low[start], low[it]);
                if(low[it]>=dis[start] && end!=-1)
                    ar[start] = 1;
                child++;
            }
            else
                low[start] = min(low[start], dis[it]);
        }
        if(end==-1 && child>1)
            ar[start] = 1;
    }
    vector<int> articulationPoints(int v, vector<int>adj[]) {
        // Code here
        vector<int> dis(v,-1);
        vector<int> low(v,-1);
        vector<bool> vis(v,0);
        int time=0;
        vector<int> ar(v,0);
        solve(0, dis, low, vis, -1, adj, time, ar);
        vector<int> res;
        for(int i=0; i<v; i++){
            if(ar[i]==1)
                res.push_back(i);
        }
        if(res.size()==0) res.push_back(-1);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
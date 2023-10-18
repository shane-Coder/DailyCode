//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int node, vector<int>adj[], vector<int>&vis){
        vis[node] = 1;
        bool res = true;
        for(auto it:adj[node]){
            if(vis[it])
                return false;
            res = res&(dfs(it, adj, vis));
        }
        vis[node] = 0;
        return res;
    }
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        vector<int>vis(v,0), res;
        for(int i=0; i<v; i++){
            if(dfs(i, adj, vis))
                res.push_back(i);
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends
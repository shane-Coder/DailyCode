//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    // code here
	    queue<pair<int, int>>q;
	    vector<int>vis(v, 0);
	    q.push({0, 0});
	    while(!q.empty()){
	        auto it = q.front();
	        q.pop();
	        int node = it.first;
	        int d = it.second;
	        vis[node] = 1;
	        if(node==x) return d;
	        for(auto i:adj[node]){
	            if(!vis[i])
	                q.push({i, d+1});
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends
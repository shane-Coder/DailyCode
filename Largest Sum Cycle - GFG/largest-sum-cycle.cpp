//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  long long cycle=-1;
  void dfs(int node, vector<int>&edge, bool visit[], bool path[]){
      visit[node] = true;
      path[node] = true;
      if(edge[node]!=-1){
          int adj = edge[node];
          if(!visit[adj]){
              dfs(adj, edge, visit, path);
          }
          else if(path[adj]){
              int curr = adj;
              long long sum = 0;
              do{
                  sum += curr;
                  curr = edge[curr];
              }while(curr!=adj);
              cycle = max(cycle, sum);
          }
      }
      path[node] = false;
  }
  long long largestSumCycle(int n, vector<int> edge)
  {
    // code here
    bool seen[n] = {0};
    bool path[n] = {0};
    for(int i=0; i<n; i++){
        if(!seen[i]){
            dfs(i, edge, seen, path);
        }
    }
    return cycle;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends
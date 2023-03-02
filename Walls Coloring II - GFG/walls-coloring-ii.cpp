//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        // write your code here
        int l=costs.size(), x=costs[0].size();
        if(x==1){
            if(l==1)
                return costs[0][0];
            return -1;
        }
        pair<int,int> m={INT_MAX,-1}, n={INT_MAX,-1};
        for(int i=0; i<x; i++){
            if(costs[0][i] < m.first){
                n = m;
                m = {costs[0][i],i};
            }
            else if(costs[0][i] < n.first){
                n = {costs[0][i],i};
            }
        }
        for(int i=1; i<l; i++){
            pair<int,int> curr={INT_MAX,-1}, prev={INT_MAX,-1};
            for(int j=0; j<x; j++){
                int val = costs[i][j];
                if(j!=m.second)
                    val += m.first;
                else
                    val += n.first;
                if(val<curr.first){
                    prev = curr;
                    curr = {val,j};
                }
                else if(val<prev.first){
                    prev = {val,j};
                }
            }
            m = curr;
            n = prev;
        }
        return m.first;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>>ar, int x, int y) {
        // code here
        vector<vector<int>>v(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        if(ar[0][0]==0 || ar[x][y]==0)
            return -1;
        v[0][0] = 0;
        q.push({0,0});
        while(!q.empty()){
            int a = q.front().first;
            int b = q.front().second;
            if(a!=0 && ar[a-1][b]==1 && v[a][b]+1<v[a-1][b]){
                q.push({a-1,b});
                v[a-1][b] = v[a][b]+1;
            }
            if(a+1!=n && ar[a+1][b]==1 && v[a][b]+1<v[a+1][b]){
                q.push({a+1,b});
                v[a+1][b] = v[a][b]+1;
            }
            if(b+1!=m && ar[a][b+1]==1 && v[a][b]+1<v[a][b+1]){
                q.push({a,b+1});
                v[a][b+1] = v[a][b]+1;
            }
            if(b!=0 && ar[a][b-1]==1 && v[a][b]+1<v[a][b-1]){
                q.push({a,b-1});
                v[a][b-1] = v[a][b]+1;
            }
            q.pop();
        }
        if(v[x][y]==INT_MAX)
            return -1;
        return v[x][y];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    bool isValid(int x, int y, int&n, int&m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    bool isBoundary(int x, int y, int &n, int &m){
        return (x==0 || y==0 || x==n-1 || y==m-1);
    }
    void noPair(int x, int y, int&n, int&m, vector<vector<char>>&mat){
        mat[x][y] = 'N';
        for(int d=0; d<4; d++){
            int i = dx[d]+x;
            int j = dy[d]+y;
            if(isValid(i, j, n, m) && mat[i][j]=='O')
                noPair(i, j, n, m, mat);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isBoundary(i, j, n, m) && mat[i][j]=='O')
                    noPair(i, j, n, m, mat);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='O')
                    mat[i][j] = 'X';
                else if(mat[i][j]=='N')
                    mat[i][j] = 'O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends
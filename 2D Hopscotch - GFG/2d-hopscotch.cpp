//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int hopscotch(int n, int m, vector<vector<int>> mat, int ty, int i, int j)
    {
        // code here
        int res=0;
        if(ty==0){
            if(j%2!=0){
                if(i-1>=0) res += mat[i-1][j];
                if(j-1>=0) res += mat[i][j-1];
                if(j+1<m) res += mat[i][j+1];
                if(i+1<n) res += mat[i+1][j];
                if(i+1<n && j-1>=0) res += mat[i+1][j-1];
                if(i+1<n && j+1<m) res += mat[i+1][j+1];
            }
            else{
                if(i-1>=0) res += mat[i-1][j];
                if(j-1>=0) res += mat[i][j-1];
                if(j+1<m) res += mat[i][j+1];
                if(i+1<n) res += mat[i+1][j];
                if(i-1>=0 && j-1>=0) res += mat[i-1][j-1];
                if(i-1>=0 && j+1<m) res += mat[i-1][j+1];
            }
        }
        else if(ty==1){
            if(j%2!=0){
                if(i-2>=0) res += mat[i-2][j];
                if(j-2>=0) res += mat[i][j-2];
                if(j+2<m) res += mat[i][j+2];
                if(i+2<n) res += mat[i+2][j];
                
                if(i+2<n && j-1>=0) res += mat[i+2][j-1];
                if(i+1<n && j-2>=0) res += mat[i+1][j-2];
                
                if(i+2<n && j+1<m) res += mat[i+2][j+1];
                if(i-1>=0 && j-2>=0) res += mat[i-1][j-2];
                
                if(i-1>=0 && j+2<m) res += mat[i-1][j+2];
                if(i+1<n && j+2<m) res += mat[i+1][j+2];
                
                if(i-1>=0 && j-1>=0) res += mat[i-1][j-1];
                if(i-1>=0 && j+1<m) res += mat[i-1][j+1];
            }
            else{
                if(i-2>=0) res += mat[i-2][j];
                if(j-2>=0) res += mat[i][j-2];
                if(j+2<m) res += mat[i][j+2];
                if(i+2<n) res += mat[i+2][j];
                
                if(i+1<n && j+2<m) res += mat[i+1][j+2];
                if(i+1<n && j-2>=0) res += mat[i+1][j-2];
                
                if(i-1>=0 && j-2>=0) res += mat[i-1][j-2];
                if(i-2>=0 && j-1>=0) res += mat[i-2][j-1];
                
                if(i-2>=0 && j+1<m) res += mat[i-2][j+1];
                if(i-1>=0 && j+2<m) res += mat[i-1][j+2];
                
                if(i+1<n && j-1>=0) res += mat[i+1][j-1];
                if(i+1<n && j+1<m) res += mat[i+1][j+1];
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>ty>>i>>j;
        
        Solution ob;
        cout<<ob.hopscotch(n, m, mat, ty, i, j)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
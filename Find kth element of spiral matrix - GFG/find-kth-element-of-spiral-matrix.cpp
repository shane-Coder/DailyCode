//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int ar[MAX][MAX], int n, int m, int k)
    {
 		// Your code goes here.
 		int up=0, down=n-1, left=0, right=m-1;
 		while(up<=down && left<=right){
 		    for(int i=left; i<=right; i++){
 		        k--;
 		        if(k==0)    return ar[up][i];
 		    }
 		    up++;
 		    for(int i=up; i<=down; i++){
 		        k--;
 		        if(k==0)    return ar[i][right];
 		    }
 		    right--;
 		    if(down>=up){
 		        for(int i=right; i>=left; i--){
 		            k--; 
 		            if(k==0)    return ar[down][i]; 
 		        }
 		        down--;
 		    }
 		    if(left<=right){
 		        for(int i=down; i>=up; i--){
 		            k--;
 		            if(k==0)    return ar[i][left];
 		        }
 		        left++;
 		    }
 		}
 		return -1;
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int perfectSum(int ar[], int n, int sum)
	{
        // Your code goes here
        int mod = 1e9+7;
        vector<vector<int>> res(n+1, vector<int>(sum+1));
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0)
                    res[i][j] = 0;
                if(j==0)
                    res[i][j] = 1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(ar[i-1]<=j)
                    res[i][j] = (res[i-1][j-ar[i-1]]%mod)+(res[i-1][j]%mod);
                else
                    res[i][j] = res[i-1][j]%mod;
            }
        }
        return res[n][sum]%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
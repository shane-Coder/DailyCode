//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int ar[], int n)  
	{  
	    // Your code goes here
	    vector<int>dp(ar, ar+n);
	    for(int i=0; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(ar[j]<ar[i]){
	                dp[i] = max(dp[i], dp[j]+ar[i]);
	            }
	        }
	    }
	    return *max_element(dp.begin(), dp.end());
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
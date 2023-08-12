//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int ar[])
    {
       // your code here
       vector<int>dp;
       int m=1;
       for(int i=0; i<n; i++){
           auto it = lower_bound(dp.begin(), dp.end(), ar[i]);
            if(it==dp.end())
                dp.emplace_back(ar[i]);
            else{
                int index = it-dp.begin();
                dp.at(index) = ar[i];
            }
           m = max(m, (int)dp.size());
       }
       return m;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
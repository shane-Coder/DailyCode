//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int ar[], int br[], int n, int m, int x) {
        //code here
        int i=0, j=m-1;
        int diff = INT_MAX;
        vector<int>res(2);
        while(i<n && j>=0){
            int total = ar[i]+br[j];
            int d = abs(total-x);
            if(d<diff){
                diff = d;
                res[0] = ar[i];
                res[1] = br[j];
            }
            if(total<x)
                i++;
            else
                j--;
        }
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
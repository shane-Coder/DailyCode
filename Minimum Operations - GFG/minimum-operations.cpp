//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        int ct=0;
        while(n){
            if(n&1)
                n--;
            else
                n = n/2;
            ct++;
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends
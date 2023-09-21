//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int ar[], int n)
    {
        // Your code here
        if(n==0)   return 0;
        if(n==1)    return ar[0];
        int a = ar[0];
        int b = max(a, ar[1]);
        for(int i=2; i<n; i++){
            int temp = b;
            b = max(b, a+ar[i]);
            a = temp;
        }
        return b;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
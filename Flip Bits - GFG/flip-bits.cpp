//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int ar[], int n)
    {
        // Your code goes here
        int res=0, zero=0, one=0;
        for(int i=0; i<n; i++){
            if(!ar[i]){
                zero++;
            }
            else{
                zero--;
                one++;
            }
            res = max(zero, res);
            if(zero<0)
                zero = 0;
        }
        return res+one;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends
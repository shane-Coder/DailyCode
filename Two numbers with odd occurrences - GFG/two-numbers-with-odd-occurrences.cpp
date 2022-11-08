//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int ar[], long long int n)  
    {
        // code here
        long long int temp=0;
        for(long long int i=0; i<n; i++)
            temp = temp^ar[i];
        int take = temp & ~(temp-1);
        int x=0, y=0;
        for(long long int i=0; i<n; i++){
            if(take&ar[i])
                x = x^ar[i];
            else
                y = y^ar[i];
        }
        if(x>y)
            return {x,y};
        return {y,x};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
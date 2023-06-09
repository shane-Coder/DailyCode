//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    public:
        void Rearrange(int ar[], int n)
        {
            // Your code goes here
            stack<int>st;
            for(int i=n-1; i>=0; i--){
                if(ar[i]>=0)
                    st.push(ar[i]);
            }
            int k=0;
            for(int i=0; i<n; i++){
                if(ar[i]<0)
                    ar[k++] = ar[i];
            }
            for(; k<n; k++){
                ar[k] = st.top();
                st.pop();
            }
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends
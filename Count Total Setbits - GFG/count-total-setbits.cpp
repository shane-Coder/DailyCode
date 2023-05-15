//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long n) {
        // code here
        vector<int>temp(n+1,0);
        long long count=0;
        for(long long i=1; i<=n; i++){
            if(i%2==0)
                temp[i] = temp[i/2];
            else
                temp[i] = temp[i/2]+1;
            count += temp[i];
        }
        return count;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
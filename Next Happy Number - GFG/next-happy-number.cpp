//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    bool happy(int n){
        if(n==1 || n==7)    return true;
        if(n==2 || n==4 || n==8 || n==3 || n==9 || n==5 || n==6)    return false;
        int num=0;
        while(n){
            int d = n%10;
            num += (d*d);
            n = n/10;
        }
        return happy(num);
    }
    int nextHappy(int n){
        // code here
        while(true){
            n++;
            if(happy(n))    return n;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends
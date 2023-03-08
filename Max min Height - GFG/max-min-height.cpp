//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        long long int maximizeMinHeight(int n, int k, int w, vector <int> &ar)
        {
            // code here
            int a = *min_element(ar.begin(), ar.end());
            int b = a+k+1;
            auto f = [&](int h){
                int day=0, curr=ar[0];
                vector<int> v(n+1);
                int d=max(0,h-curr);
                v[0] += d;
                day += d;
                v[w] -= d;
                for(int i=1; i<n; i++){
                    v[i] += v[i-1];
                    int ht = ar[i]+v[i];
                    d = max(0,h-ht);
                    v[i] += d;
                    day += d;
                    if(i+w<n)
                        v[i+w] -= d;
                }
                return day<=k;
            };
            while(a<b){
                int ht = (a+b)/2;
                if(!f(ht))
                    b = ht;
                else
                    a = ht+1;
            }
            return a-1;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends
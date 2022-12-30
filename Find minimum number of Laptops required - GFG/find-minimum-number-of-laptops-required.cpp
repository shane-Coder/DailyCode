//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int n, int start[], int end[]) {
        // Code here
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++){
            v.push_back({start[i], 1});
            v.push_back({end[i], -1});
        }
        sort(v.begin(), v.end());
        int res=0, ct=0;
        for(int i=0; i<v.size(); i++){
            ct += v[i].second;
            res = max(res, ct);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        // code here
        unordered_map<int,int>mp;
        int m=0;
        for(int i=0; i<n; i++){
            mp[tasks[i]]++;
            m = max(m,mp[tasks[i]]);
        }
        int res=(m-1)*(k+1);
        for(auto it:mp){
            if(it.second==m)    res++;
        }
        return max((int)tasks.size(),res);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends
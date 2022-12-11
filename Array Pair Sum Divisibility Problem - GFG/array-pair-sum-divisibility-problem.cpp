//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2!=0) return false;
        unordered_map<int,int> mp;
        for(auto it:nums)
            mp[it%k]++;
        for(auto it:mp){
            int val=it.first, key=abs(k-it.first);
            if(val==0 && mp[val]%2==0)
                continue;
            if(mp.find(key)==mp.end()) return false;
            if(mp[val]!=mp[key]) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
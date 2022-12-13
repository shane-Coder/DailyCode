//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        vector<int> v(n,1);
        for(int i=0; i<n; i++){
            if(str[i]=='0')
                v[i] = 1;
            else
                v[i] = -1;
        }
        vector<int> res;
        int start=-1, end=-1, take=0;
        int cur=0, m=INT_MIN;
        for(int i=0; i<n; i++){
            cur += v[i];
            if(m<cur){
                m = cur;
                start = take;
                end = i;
            }
            if(cur<0){
                take = i+1;
                cur = 0;
            }
        }
        if(m==-1)
        {
            res.push_back(-1);
            return res;
        }
        res.push_back(start+1);
        res.push_back(end+1);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends
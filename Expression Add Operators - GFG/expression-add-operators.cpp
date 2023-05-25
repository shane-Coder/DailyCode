//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  void dfs(int index, string s, int target, vector<string>&res, string temp, long long prev, long long ans){
        if(index==s.size()){
            if(ans==target)
                res.push_back(temp);
            return;
        }
        string v="";
        long long curr=0;
        for(int j=index; j<s.size(); j++){
            if(j>index && s[index]=='0')
                break;
            v += s[j];
            curr = curr*10 + (s[j]-'0');
            if(index==0){
                dfs(j+1, s, target, res, temp+v, curr, curr);
            }
            else{
                dfs(j+1, s, target, res, temp+"+"+v, curr, ans+curr);
                dfs(j+1, s, target, res, temp+"-"+v, -curr, ans-curr);
                dfs(j+1, s, target, res, temp+"*"+v, prev*curr, ans-prev+(prev*curr));
            }
        }
    }
  public:
    vector<string> addOperators(string s, int target) {
        // code here
        vector<string>res;
        string temp="";
        long long prev=0;
        dfs(0, s, target, res, temp, prev, 0);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    struct Trie{
        Trie*ar[26];
        vector<string>str;
        Trie(){
            for(int i=0; i<26; i++)
                ar[i] = NULL;
                str.clear();
        }
    };
    void insert(string s, Trie*root){
        for(int i=0; i<s.size(); i++){
            if(s[i]<'A' || s[i]>'Z')    continue;
            if(root->ar[s[i]-'A']==NULL){
                Trie*node = new Trie();
                root->ar[s[i]-'A'] = node;
            }
            root = root->ar[s[i]-'A'];
            root->str.push_back(s);
            i++;
            while(i<s.size() && s[i]>='a' && s[i]<='z')
            i++;
            i--;
        }
    }
    void solve(Trie*root, string p, vector<string>&res){
        for(int i=0; i<p.size(); i++){
            if(root!=NULL && root->ar[p[i]-'A']!=NULL)
                root = root->ar[p[i]-'A'];
            else
                return ;
        }
        if(root==NULL)  return ;
        res = root->str;
    }
    vector<string> CamelCase(int n, vector<string> Dictionary, string Pattern) {
        // code here
        Trie*root = new Trie();
        for(int i=0; i<Dictionary.size(); i++){
            insert(Dictionary[i], root);
        }
        vector<string>res;
        solve(root, Pattern, res);
        if(res.size()==0)
            return {"-1"};
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
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
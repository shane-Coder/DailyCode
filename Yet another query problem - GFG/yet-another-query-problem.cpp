//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &ar, vector<vector<int>> &q) {
        // code here
        map<int,int> mp;
        vector<int> freq(n,0);
        for(int i=n-1; i>=0; i--){
            mp[ar[i]]++;
            freq[i] = mp[ar[i]];
        }
        vector<int> res(num);
        for(int i=0; i<num; i++){
            int l=q[i][0], r=q[i][1], k=q[i][2];
            int ct = 0;
            for(int j=l; j<=r; j++){
                if(freq[j]==k)
                    ct++;
            }
            res[i] = ct;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends
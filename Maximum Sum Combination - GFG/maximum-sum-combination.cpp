//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        for(int i=0; i<N; i++){
            int total = A[i]+B[N-1];
            pq.push({total, N-1});
        }
        while(!pq.empty() && K--){
            int total = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            res.push_back(total);
            if(index-1>=0)
                pq.push({total-B[index]+B[index-1], index-1});
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
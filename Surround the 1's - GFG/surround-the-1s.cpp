//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        // Code here
        int row=matrix.size(), col=matrix[0].size();
        int res=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j]==0)
                    continue;
                int ct=0;
                int r_ar[] = {-1,-1,-1,0,1,1,1,0};
                int c_ar[] = {-1,0,1,1,1,0,-1,-1};
                for(int k=0; k<8; k++){
                    int x = i+r_ar[k];
                    int y = j+c_ar[k];
                    if(x>=0 && x<row && y>=0 && y<col && matrix[x][y]==0)
                        ct++;
                }
                if(ct!=0 && ct%2==0)
                    res++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
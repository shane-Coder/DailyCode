//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool dfs(int i, int j, int x, int y, vector<vector<char>>&grid, string&w, int index){
        if(index==w.length())   return true;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=w[index])   return false;
        return dfs(i+x, j+y, x, y, grid, w, index+1);
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>>res;
	    int x[8] = {0,-1,-1,-1,0,1,1,1};
	    int y[8] = {-1,-1,0,1,1,1,0,-1};
	    for(int i=0; i<grid.size(); i++){
	        for(int j=0; j<grid[0].size(); j++){
	            if(grid[i][j]==word[0]){
	                for(int k=0; k<8; k++){
	                    if(dfs(i, j, x[k], y[k], grid, word, 0)){
	                        res.push_back({i,j});
	                        break;
	                    }
	                }
	            }
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:

    void mapParent(Node*root, Node*head, map<Node*,Node*>&mp, int target, Node* &take){
        if(root==NULL)  return ;
        mp[root] = head;
        if(!take && root->data==target)
            take = root;
        mapParent(root->left, root, mp, target, take);
        mapParent(root->right, root, mp, target, take);
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        vector<int>res;
        map<Node*, Node*> mp;
        Node*take = NULL;
        mapParent(root, NULL, mp, target, take);
        queue<pair<Node*, int>>q;
        q.push({take, 0});
        map<Node*, bool>visit;
        visit[take] = true;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int d;
                Node*head;
                tie(head, d) = q.front();
                q.pop();
                if(d==k){
                    res.push_back(head->data);
                }
                else if(d<k){
                    if(head->left && !visit[head->left]){
                        q.push({head->left, d+1});
                        visit[head->left] = true;
                    }
                    if(head->right && !visit[head->right]){
                        q.push({head->right, d+1});
                        visit[head->right] = true;
                    }
                    if(mp[head] && !visit[mp[head]]){
                        q.push({mp[head], d+1});
                        visit[mp[head]] = true;
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    Node*find(Node*head, int target){
        if(head==NULL || head->data==target)
            return head;
        if(head->data > target)
            return find(head->left, target);
        else
            return find(head->right, target);
    }
public:
    int sum(Node*head, int target){
        if(head==NULL)
            return 0;
        if(head->data == target)
            return head->data;
        if(head->data > target)
            return head->data + sum(head->left, target);
        else
            return head->data + sum(head->right, target);
    }
    int minSum(Node*head){
        if(head==NULL)
            return 0;
        if(head->left==NULL && head->right==NULL)
            return head->data;
        if(head->left==NULL)
            return head->data + minSum(head->right);
        if(head->right==NULL)
            return head->data + minSum(head->left);
        return min(head->data + minSum(head->left), head->data + minSum(head->right));
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        Node*head = find(root, target);
        if(head==NULL)
            return -1;
        int first = sum(root, head->data) - head->data;
        int second = minSum(head) - head->data;
        return first - second;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends
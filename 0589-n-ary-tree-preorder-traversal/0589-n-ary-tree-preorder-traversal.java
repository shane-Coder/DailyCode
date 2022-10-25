/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<Integer> ar = new ArrayList<>();
    public List<Integer> preorder(Node root) {
        if(root==null)
            return ar;
        
        ar.add(root.val);
        for(Node curr: root.children)
            preorder(curr);
        return ar;
    }
}
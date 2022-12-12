// DFS Approach
// Time Coplexity = O(N)
// Space Complexity = O(h)
// where n is the number of nodes in the tree.


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node* left, Node* right) {
        //base case
        if (left == NULL) {
            return;
        }
        
        //logic
        
        left->next = right;
        
        dfs(left->left,left->right);
        dfs(left->right,right->left);
        dfs(right->left,right->right);
    }
    
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        dfs(root->left,root->right);
        return root;
        
    }
};
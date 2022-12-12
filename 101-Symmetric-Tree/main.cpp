//DFS approach

/*
 Time Complexity = O(N)
 Space Complexity = O(h)
 Where N is the number of nodes in the tree and h is the height of the tree.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left,root->right);
    }
    bool dfs (TreeNode* left, TreeNode* right) {
        //base
        if (left == NULL && right == NULL) return true;
        
        if (left == NULL || right == NULL || left->val != right->val) return false;
        
        return dfs(left->left,right->right) && dfs(left->right, right->left);
    }
};


//BFS approach

/*
 Time Complexity = O(N)
 Space Complexity = O(h)
 Where N is the number of nodes in the tree and h is the height of the tree.
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
     queue <TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while (!q.empty()) {
            TreeNode* left1 = q.front();
            q.pop();
            TreeNode* right1 = q.front();
            q.pop();
            if (left1 == NULL && right1 == NULL) continue;
            //if two nodes are NULL that does not mean that the tree is symm it can or cannot be symm
            
            if (left1 == NULL || right1 == NULL || left1->val != right1->val) return false;
            
            q.push(left1->left);
            q.push(right1->right);
            q.push(left1->right);
            q.push(right1->left);
            
            
            
        }
        return true;
    }
  
};
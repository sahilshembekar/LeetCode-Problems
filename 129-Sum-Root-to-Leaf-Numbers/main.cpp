// One global variable sum and one local variable num
// Void return

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
    void helper(TreeNode* root, int num) {
        //base 
        if (root == NULL) {
            return;
        }
        
        //logic
        
        helper(root->left, num*10 + root->val);
        //st.pop Auto
        
        if (root->left == NULL && root->right == NULL) {
            //That is we have a leaf node
            sum = sum + num*10 + root->val;
        }
        helper(root->right, num*10 + root->val);
        //st.pop Auto
    }
    
public:
    int sum=0;
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return sum;
        }
        helper(root,0);
        return sum;
    }
};


// Two local variable num
// int return

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
    int helper(TreeNode* root, int num) {
        //base 
        if (root == NULL) {
            return 0;
        }
        
        //logic
        if (root->left == NULL && root->right == NULL) {
            //That is we have a leaf node
            return num*10 + root->val;
            // The root i.e. node will not go in stack if we have leaf node
        }
        
        return helper(root->left, num*10 + root->val) + helper(root->right, num*10 + root->val);
    }
    
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        return helper(root,0);
    }
};
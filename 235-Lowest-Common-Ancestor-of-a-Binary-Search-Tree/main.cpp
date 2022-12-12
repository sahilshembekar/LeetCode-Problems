//Recursive Solution

// Time Complexity = O(h)
// Space Complexity = O(h)
// where h is the height of the tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right,p,q);
        }
        else {
            return root;
        }
    }
};


//Iterative Solution

// Time Complexity = O(h)
// Space Complexity = O(1)
// where h is the height of the tree.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) { //Until LCA is not found
            if(root->val > p->val && root->val > q->val) {
                root = root->left; //Not a recursive call just go left
            }
            else if(root->val < p->val && root->val < q->val) {
                root = root->right; //Not a recursive call just go right
            }
            else {
                return root;
            }
        }
    }
};
/*
Time Complexity = O(NlogN)
Space Complexity = O(h)
where N is the number of nodes in the tree and h is the height of the tree.
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
    bool isBalanced(TreeNode* root) {
     if (root == NULL) {
         return true;
     }
        if ( abs(height(root->left) - height(root->right)) > 1) {
            return false;
        }
            return isBalanced(root->left) && isBalanced(root->right);
        
    
    }
    int height(TreeNode* root) {
        //Base case
        if (root == NULL) return 0;
        
        return max(height(root->left), height(root->right)) + 1;
    }
};

/*
Time Complexity = O(N)
Space Complexity = O(h)
where N is the number of nodes in the tree and h is the height of the tree.
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
    bool isBalanced(TreeNode* root) {
     if (root == NULL) {
         return true;
     }
        if(height(root) == -1) {
            return false;
        }
        else {
            return true;
        }
    
    }
    int height(TreeNode* root) {
        //Base case
        if (root == NULL) return 0;
        
        //Take the height from left and right child
        int left = height(root->left);
        int right = height(root->right);
        
        //If unbalanced then we return -1 instead of the height itself
        if (abs(left-right) > 1) {
            return -1;
        }
        
        //In case a part of big tree is unbalanced, we return and pass the -1 till the top of the chain i.e. till root
        if(left == -1 || right == -1) {
            return -1;
        }
        
        //If we have balanced situation we calculate the height and return that
        return max(left,right) + 1;
    }
};
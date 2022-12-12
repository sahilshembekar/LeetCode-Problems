// No inorder
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
    //eeNode* Prev;
public:
    TreeNode* Prev= NULL;
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        while (root != NULL || st.empty() == false) {
            while (root!= NULL) {
                st.push(root);
                root = root -> left;
            }
            root = st.top();
            st.pop();    
        
        if (Prev != NULL && Prev->val >= root->val) {
            return false;
        }
        Prev = root;       
        root = root ->right;
        }
        return true;
    }
    
};
 // Void inorder()
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
    
    bool result=true;
    TreeNode *prev=NULL;
    
    void inorder(TreeNode* root) {
        if (root == NULL) {
            return ;
        }
        inorder(root->left);
        if (prev!= NULL && prev->val >= root->val) {
            result = false;
        }
        prev = root;
        inorder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        
         
        inorder(root);
        return result;
    }
};


// bool inorder()
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
    
    bool flag=true;
    TreeNode *prev=NULL;
    
    bool inorder(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        inorder(root->left);
        if (prev!= NULL && prev->val >= root->val) {
            flag = false;
        }
        prev = root;
        inorder(root->right);
        return flag;
    }
public:
    bool isValidBST(TreeNode* root) {
        
        return inorder(root);
    }
};
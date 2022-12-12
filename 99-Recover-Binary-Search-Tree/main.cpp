// Iterative Approach

// Time Complexity = O(n)
// Space Complexity = O(h)  for stack
// where n is the number of nodes and h is the height of the tree.

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
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    TreeNode* prev = NULL;
    bool mismatch = false; //Can do withiout this flag as well
    
    void recoverTree(TreeNode* root) {
        //NULL case
        if (root == NULL) {
            return;
        }
        
        inorder(root);
        
        //Swap the Nodes causing error
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    
    void inorder(TreeNode* root) {
        
        stack<TreeNode*> st;
        while (root != NULL || !st.empty()) {
            while(root != NULL) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (prev!= NULL && prev->val >= root->val) {
                //Tells us violation has occured
                if (!mismatch) {
                    //Shows that this is the first occurence
                    first = prev;
                    second = root; //To cover the problem if violation occurs in adjacent nodes
                    mismatch = true;
                }
                else {
                    //for second violation only
                    second = root; //overwrite the command in the if loop since the violation nodes aren't adjacent
                    //mismatch= false; //for optimization way 2
                    return; // we return here itself as we found the violations // for optimization
                }
            }

            prev = root;
            root = root->right;
        }
                
    }
};
/*
for next().  TC = O(h) -> Worst case when we go from top to bottom. Average TC = O(1), SC = O(1)
for hasnext().  TC = O(1), SC = O(1)
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
class BSTIterator {
public:
    stack <TreeNode*> st;
    
    BSTIterator(TreeNode* root) {
        dfs(root);
    }
    
    int next() {
        TreeNode* result = st.top();
        st.pop();
        dfs(result->right); // Make the dfs go to the right of Node that was popped out till it hits NULL
        return result->val;
    }
    
    bool hasNext() {
        return !st.empty();
        
    }
    
    void dfs(TreeNode* root) { //Go deeper till we find root as NULL basically till leaf
        while (root!= NULL) {
            st.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
/*
Time Complexity = O(N)
 Space Complexity = O(h)
 where N is the number of nodes of the tree and h is the hieght of the tree.
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
    TreeNode* x_parent;
    TreeNode* y_parent;
    int x_depth;
    int y_depth;
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) {
            return false;
        }
        dfs(root,x,y,0,NULL);
        return x_depth == y_depth && x_parent!=y_parent;
    }
    void dfs(TreeNode* root, int x, int y, int depth, TreeNode* parent) {
        //base case
        if (root == NULL) {
            return;
        }
        
        //logic
        
        if(root->val == x) {
            x_depth = depth;
            x_parent = parent;
        }
        if(root->val == y) {
            y_depth = depth;
            y_parent = parent;
        }
        
        dfs(root->left,x,y,depth+1,root);
        //st.pop() auto
        dfs(root->right,x,y,depth+1,root);
        //st.pop() auto
        // we can put left before logic, then logic, inorder
        // left and right both before logic, postorder
    }
};


//Aprroach 2
/*
 Time Complexity = O(N) // 1 traversal
 Space Complexity = O(N) // queue
 Where N is the number of nodes of the tree.
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
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL) return false;
        
        queue <TreeNode *> q;
        q.push(root);
        
        bool x_found = false;
        bool y_found = false;
        while(!q.empty()) {
            int size = q.size();
            //Treat them as distict elements based on levels and not iterate extra when level changed
            for (int i=0; i< size; i++) {
                TreeNode * curr = q.front();
                q.pop();
                if (curr->val == x) {
                    x_found = true;
                }
                if (curr->val == y) {
                    y_found = true;
                }
                // make the resp flags true once we find them
                
                if (curr->left != NULL && curr->right != NULL) { // Only check the babies if they are not NULL
                    if (curr->left->val == x && curr->right->val == y) {
                        return false;
                    }
                    if (curr->left->val == y && curr->right->val == x) {
                        return false;
                    }
                    // If the above conditions is satisfied this means they have the same parent i.e. curr and they are brothers not cousins
                    //we make this check before pushing the babies inside the queue
                }
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
                
            }
            if (x_found && y_found) return true;
            // if these conditions get satisfied at the same level only then flags will become true and hence found 
            if (x_found || y_found) return false;
            // if one of them is found and other is not found means both are not at the same level hence depth is diff i.e. not cousins
        }
        return false; //otherwise
    }
};
//BFS approach

/*
Time Complexity = O(N)
 Space Complexity = O(N)
 where N is the number of nodes in the tree.
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
    vector<int> rightSideView(TreeNode* root) {
        vector <int> result;
        if (root == NULL) {
            return result;
        }
        queue <TreeNode *> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            
            for (int i=0; i< size; i++) {
                TreeNode * curr = q.front();
                q.pop();
                if (i == size -1 ) { //Basically last node of that level i.e. rightmost node
                    // if we do i == 0 then we get left side view of tree
                    result.push_back(curr->val);
                }
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }
        return result;
    }
};


//DFS approach
// with recursive right call first

/*
Time Complexity = O(N)
 Space Complexity = O(h)
 where N is the number of nodes in the tree.
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
    vector <int> result;
    public:
    vector<int> rightSideView(TreeNode* root) {
        
        if (root == NULL) {
            return result;
        }
        dfs(root,0);
        return result;
    }
    void dfs(TreeNode* root, int level) {
        //base 
        if (root == NULL) {
            return;
        }
        
        //logic
        
        if (result.size() ==  level) {
            result.push_back(root->val);
        }
        dfs(root->right,level+1);
        dfs(root->left,level+1);
        
    }
};


//DFS approach
// with recursive left call first and overwrite

/*
Time Complexity = O(N)
 Space Complexity = O(h)
 where N is the number of nodes in the tree.
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
    vector <int> result;
    public:
    vector<int> rightSideView(TreeNode* root) {
        
        if (root == NULL) {
            return result;
        }
        dfs(root,0);
        return result;
    }
    void dfs(TreeNode* root, int level) {
        //base 
        if (root == NULL) {
            return;
        }
        
        //logic
        
        if (result.size() ==  level) {
            result.push_back(root->val);
        }
        else {
            result[level] = root->val;
        }
        
        dfs(root->left,level+1);
        dfs(root->right,level+1);
        
    }
};
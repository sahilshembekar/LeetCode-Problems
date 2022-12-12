// Using BFS 
/*
Time complexity = O(N)
 Space complexity = O(N)
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == NULL) {
            return result;
        }
        queue <TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector <int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                vec.push_back(curr->val);
                
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};


// Using DFS 
/*
Time complexity = O(N)
 Space complexity = O(h)
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
    vector<vector<int>> result;
    public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (root == NULL) {
            return result;
        }
        dfs(root,0);
        return result;
    }
    
    void dfs (TreeNode * root, int level) {
        //base case
        if (root == NULL) {
            return ;
        }
        
        //logic
        if (result.size() == level) {
            vector <int> vec;
            vec.push_back(root->val);
            result.push_back(vec);
        }
        else {
            result[level].push_back(root->val);
        }
        dfs(root->left,level+1);
        dfs(root->right,level+1);
    }
};
// Recursive Solution
// Time Complexity = O(N)
// Space Complexity = O(h)
// where n is the height of the tree and h is the height of the tree.


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
    vector <TreeNode*> ppath;
    vector <TreeNode*> qpath;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //NULL case
        if (root == NULL || p == root || q == root) {
            return root;
        }
        
        vector <TreeNode*> path;
        backtrack(root,p,q,path);
        //Iterate over both paths and find the LCA
        for (int i =0; i<ppath.size(); i++) {
            if (ppath[i] != qpath[i]) {
                //Return the Node which is juts 1 before the node where we found the difference in path that will be the LCA 
                return ppath[i-1];
            }
        }
        return NULL;
    }
    
    void backtrack(TreeNode* root, TreeNode* p, TreeNode* q, vector <TreeNode*> &path) {
        //Base Case
        if (root == NULL) {
            return;
        }
        
        //Logic
        
        //action
        path.push_back(root);
        
        //Condition
        if (root->val == p->val) {
            // if p is found copy the path to ppath
            ppath = path;
            //add same root once more to handle complication
            ppath.push_back(root);
            //ppath.push_back(root);
            //We will have to add the extra same root twice if we do preorder Traversal i.e.
            // if we do condition before the action
            //Reason is in preoder traversal the path will be copied in ppath before the action is even done
            //So we will be basically making a ppath before the action has even happened and out extra will be the only instance of the last root added
            //it will not act as extra // hence twice
            
            //can also be added to path instead of ppath but in that case we will have do 2 things
            //1. Add it to path twice Reason same as above
            //2. Backtrack twice i.e. path.pop_back() to implement backtracking as we are making changing to the orginal path which impacts all path not just ppath or qpath
        }
        if (root->val == q->val) {
            // if q is found copy the path to qpath
            qpath = path;
            //add same root once more to handle complication
            qpath.push_back(root);
            //qpath.push_back(root);
        }
        
        
        //Recurse
        
        backtrack(root->left,p,q,path);
        backtrack(root->right,p,q,path);
        
        //backtrack
        path.pop_back();
    }
};
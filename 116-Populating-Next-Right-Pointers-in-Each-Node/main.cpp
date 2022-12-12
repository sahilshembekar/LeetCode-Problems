// DFS Approach
// Time Coplexity = O(N)
// Space Complexity = O(h)
// where n is the number of nodes in the tree.


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void dfs(Node* left, Node* right) {
        //base case
        if (left == NULL) {
            return;
        }
        
        //logic
        
        left->next = right;
        
        dfs(left->left,left->right);
        dfs(left->right,right->left);
        dfs(right->left,right->right);
    }
    
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        dfs(root->left,root->right);
        return root;
        
    }
};


// BFS Approach with queue
// Time Coplexity = O(N)
// Space Complexity = O(h)
// where n is the number of nodes in the tree.


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        queue <Node*> q;
        q.push(root);
        Node* curr = NULL;
        
        while(!q.empty()) {
            int size = q.size();
            // first element is taken and popped
            curr = q.front();
            q.pop();
            //Go the babies add them to the queue
            if(curr->left != NULL) {
                q.push(curr->left);
            }
            if(curr->right != NULL) {
                q.push(curr->right);
            }
            //here we start i from 1
            for (int i=1; i<size; i++) {
                Node* temp = q.front();
                q.pop();
                
                curr->next = temp; //Node has next pointer use that to assign values
                //Link is established
                curr = temp;
                
                //Add the babies to the queue before losing access
                
                if(curr->left != NULL) {
                q.push(curr->left);
                }
                
                if(curr->right != NULL) {
                q.push(curr->right);
                }
            }
        }
        return root;
    }
};

// BFS Approach without extra space // fast
// Time Coplexity = O(N)
// Space Complexity = O(1)
// where n is the number of nodes in the tree.


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return NULL;
        }
        
        Node* level=root;
        Node* curr= NULL;
        while(level->left!= NULL) {
            curr=level;
            while(curr != NULL) {
                curr->left->next = curr->right;
                
                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;
                }
                curr=curr->next;
            }
            level=level->left;
        }
        return root;
    }
};
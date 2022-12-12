//BFS approach


/*
Time Complexity = O(NK)
Space Complexity = O(NK)
where n is the number of strings and k is the average length of the strings.
*/

class Solution {
public:
    //Implementation of TrieNode
    class TrieNode {
        public:
        TrieNode *children[26];
        string word = "";
    };
    
    TrieNode *root;
    Solution() { //constructor
        root = new TrieNode();
        for (int i = 0; i<26; i++) {
            root->children[i] = NULL;
        }
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(int i=0; i<word.length(); i++) {
            char ch = word[i];
            if (curr->children[ch -'a'] == NULL) {
                curr->children[ch -'a'] = new TrieNode();
            }
            curr = curr->children[ch -'a'];
        }
        curr->word = word; // At the end at each word we will add the word itself w, wo, wor, worl ...
    }
    
    string longestWord(vector<string>& words) {
        //insert all the words in the TrieNode DS
        for (int i=0; i<words.size(); i++) {
            insert(words[i]);
        }
        
        
        queue <TrieNode*> q; 
        q.push(root);
        TrieNode * curr; //Made global out of the for loop because we use it in return
        
        while(!q.empty()) {
            curr = q.front();
            q.pop();
            for (int i=25; i>=0; i--) {
                //to get the correct lexicographical order we reverse iterate
                if (curr->children[i] != NULL && curr->children[i]->word != "") {
                    // if there are babies and if the correpnding word also exists i.e. w,wo,wor,worl only then do something
                    q.push(curr->children[i]);
                }
            }
        }
        //to target NULL case //Maybe needed 
        if (curr->word == "") {
            return "";
        }
        return curr->word;
    }
};
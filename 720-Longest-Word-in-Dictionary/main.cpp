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


//DFS approach


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
    
    string result ="";
    string longestWord(vector<string>& words) {
        //insert all the words in the TrieNode DS
        for (int i=0; i<words.size(); i++) {
            insert(words[i]);
        }
        
        dfs(root);
        return result;
    }
    
    void dfs(TrieNode *curr) {
        //base case
        if (curr->word != "" && (curr->word).length() >= result.length()) {
            //if there is word and also check if the word size is bigger then result then add // also equal because worly will be processed first then world so in case of equal also 
            //the for take care of retur world after worly
            result = curr->word;
        }
        
        
        //logic
        for (int i=25; i>=0;i--) {
            //to get the correct lexicographical order we reverse iterate
            if (curr->children[i] != NULL && curr->children[i]->word != "") {
                // if there are babies and if the correpnding word also exists i.e. w,wo,wor,worl only then do something
                dfs(curr->children[i]); //do dfs on babies and go to babies babies and so on
            }
        }
    }
};

//DFS approach
//Backtracking i.e. optimized
//can be more optimized if we do not use char in each TrieNode

/*
Time Complexity = O(NK)?
Space Complexity = O(NK)?
where n is the number of strings and k is the average length of the strings.
*/

class Solution {
public:
    //Implementation of TrieNode
    class TrieNode {
        public:
        TrieNode *children[26];
        bool isEnd; //we hjust check if the end is here or not
        char ch;
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
            curr->ch = ch;
        }
        curr->isEnd = true; // At the end at each word we will make it true for w, wo, wor, worl ...
        
    }
    
    string result ="";
    string longestWord(vector<string>& words) {
        //insert all the words in the TrieNode DS
        for (int i=0; i<words.size(); i++) {
            insert(words[i]);
        }
        string path = "";
        dfs(root, path);
        return result;
    }
    
    void dfs(TrieNode *curr, string &path) {
        //base case
        if (path.length() >= result.length()) {
            //if there is a path and path is longer than result then add // also equal because worly will be processed first then world so in case of equal also 
            //the for take care of return world after worly
            result = path;
        }
        
        
        //logic
        for (int i=25; i>=0;i--) {
            //to get the correct lexicographical order we reverse iterate
            if (curr->children[i] != NULL && curr->children[i]->isEnd) {
                // if there are babies and if the flag is true that is there is word that we have there i.e. w,wo,wor,worl only then do something
                
                //action
                path.push_back(curr->children[i]->ch);
                
                // recurse
                dfs(curr->children[i], path); //do dfs on babies and go to babies babies and so on
                
                
                //backtrack
                
                path.pop_back();
            }
        }
    }
};
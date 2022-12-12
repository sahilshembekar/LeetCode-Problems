/*
Insert Function
Time Complexity = O(L)
Space Complexity = O(NK)

Search Function
Time Complexity = O(L)
Space Complexity = O(NK)

StartWith Function
Time Complexity = O(L)
Space Complexity = O(NK)
where L is the length of the word, N is the number of the words and K is the average length of the word.
*/


class Trie {
public:
    class TrieNode { //Our TrieNode contains and array of 26 Trienode and bool isEnd 
        public:
        TrieNode *children[26];
        bool isEnd;
    };
    
    TrieNode *root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
        for (int i=0;i<26; i++) { //Initialize the array with NULL values 
            root->children[i] = NULL;
        }
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for (int i=0;i<word.length(); i++) {
            char ch = word[i];
            if (curr->children[ch - 'a'] == NULL) { //if it is NULL then add a TrieNode at that specific index for that character 
                curr->children[ch - 'a'] = new TrieNode(); 
            }
            curr = curr->children[ch -'a']; //then go to the baby by making the curr to the curr->children
        }
        curr->isEnd = true; //At the end of the word make the flag true
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for (int i=0;i<word.length(); i++) {
            char ch = word[i];
            if (curr->children[ch - 'a'] == NULL) { //is there a trieNode here? If NULL then go in 
                return false; //Basically if this character does not exist then the word does not exist 
            }
            curr = curr->children[ch -'a']; //then go to the baby by making the curr to the curr->children
        }
        return curr->isEnd; //if we store the word cattle and search cat then for the first 't' our flag will false hence cat is not stored if cattle is searched then we have true at e therefore we will get true        
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for (int i=0;i<prefix.length(); i++) {
            char ch = prefix[i];
            if (curr->children[ch - 'a'] == NULL) { //is there a trieNode here? If NULL then go in 
                return false; //Basically if this character does not exist then the word does not exist i.e. nothing for this prefix 
            }
            curr = curr->children[ch -'a']; //then go to the baby by making the curr to the curr->children
        }
        return true; //if we have the prefix then it means that we have some word like for example prefix entered is cat does not matter if we have cat or cattle it will return true as cat exists 
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
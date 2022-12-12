/*
Time Complexity = O(NK) + O(L)
Space Complexity = O(NK) + O(L)
where n is the number of words in the sentences, K is the average length of words and L is the length of the sentences.
*/

class Solution {
public:
    
    class TrieNode {
        public:
        TrieNode *children[26];
        bool isEnd;
    };
    
    
    TrieNode *root;
    Solution(){ //Contrsuctor for solution class
        root = new TrieNode();
        for (int i=0; i<26; i++) { //initialize the value of children array to NULL
            root->children[i] = NULL;
        }
    }
    
    void insert(string word) { //insert word in Trieode DS
        TrieNode *curr = root; //pointer and root and start from there now
        for (int i=0; i<word.length(); i++) {
            char ch = word[i];
            if (curr->children[ch - 'a'] == NULL) {
                curr->children[ch - 'a'] = new TrieNode();
            }
            curr = curr->children[ch - 'a']; // got to babies of curr and make that as curr
        }
        curr->isEnd = true; // make the flag of the last char as true
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        for (int i=0; i<dictionary.size(); i++) { //time = O(m*k)
            insert(dictionary[i]); //insert the words from the dictionary one by one into the TrieNode 
        }
        istringstream ss(sentence); //Take the entire sentence considering the spaces in the middle
        string finalstring;
        string word;
        int count =0;
        while (ss >> word) { // Stream the sentence till whitespace is encountered basically we will get a word // Constraint has space after each word
            //split the sentence in word(s)
            if (count) {
                finalstring.append(" "); // append same space in the final output as we did have in the input
            }
            count++;
            string replace;
            TrieNode *curr = root; //pointer and root and start from there now
            for (int j =0; j<word.length();j++) {
                char ch = word[j];
                if (curr->children[ch -'a'] == NULL || curr->isEnd) {
                    // if we there are no more characters after this or if we have reached the end of the word 
                    //come out of the loop
                    break;
                }
                curr = curr->children[ch -'a']; // if not the above case then just move to the babies of curr and make them as curr
                replace.push_back(ch); // Push every character in our replacement string
            }
            if(curr->isEnd) {
                //basically we have found the replacement word so we will add that as a part of of output sentence
                finalstring.append(replace);
            }
            else {
                //bascially we did not find a replacement as there is no replacement available in the dictionary
                //just use the same word
                finalstring.append(word);
            }
        }
        return finalstring;
        
    }
};
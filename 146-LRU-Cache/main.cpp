/*
get() function
Time Complexity = O(1)
Space Complexity = O(capacity)

put() function
Time Complexity = O(1)
Space Complexity = O(capacity)
*/

class LRUCache {
public:
    //doubly linked list therefore both prev and next
    class Node {
        public:
        int key,value;
        Node *next;
        Node *prev;
        
        Node (int key, int value) { // parameterized constructor
            this->key = key;
            this->value = value;
        }
    };
    
    void removeNode(Node *node) { //Pass the reference to the node to remove the node 
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    void addToHead(Node *node) {  //Pass the reference to the node to add the node @ head
        node->next = head->next;
        node->prev = head;
        head->next = node;
        node->next->prev = node;
    }
    
    Node *head;
    Node *tail;
    
    map<int, Node* > m;
    int cap;
    
    LRUCache(int capacity) {
        head = new Node (-1,-1); //Initialize a dummy node for head
        tail = new Node (-1,-1); //Initialize a dummy node for tail
        
        //To make it a doubky liked list
        head->prev = NULL;
        head->next = tail;
        tail->prev = head;
        tail->next = NULL;
        cap = capacity; //max for the LRU cache
    }
    
    int get(int key) {
        if (m.find(key) != m.end()) {// Basically if we find the key
            // we need to return the value for this key
            Node *node = m[key]; //get the reference of the respective node from the value of map through key
            removeNode(node); // remove the node from its old position
            addToHead(node); // add the node to head // most recently used node
            return node->value; //return the actual value from the node
        }
        return -1; //basically we did not find the node for the key that was entered
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) { //if we find the key
            //Update the value and move to the front that is recently used
            Node *node = m[key];
            node->value = value; //Value updated
            removeNode(node);
            addToHead(node);            
        }
        else {
            if (cap == m.size()) {
                //we reach the capacity // now we will remove the LRU node from the back first
                Node *tailprev = tail->prev;
                removeNode(tailprev);
                
                //Important to delete from the map as well
                m.erase(tailprev->key); //can we do key?
            }
            // Add the fresh Node
            Node *newNode = new Node(key,value); //from the parameters above
            addToHead(newNode);
            m[key] = newNode; //adding the reference of newNode to the map
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
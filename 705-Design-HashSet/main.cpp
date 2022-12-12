class MyHashSet {
public:
    vector<vector<bool>> storage;
    int buckets;
    int bucketItems;
    
    MyHashSet() {
    /*Initialize in the construtor and declared globally  */
        buckets = 1000;
        bucketItems = 1000;
        storage.resize(buckets,vector<bool>());
    }
    
    int getBuckets(int key) {
        /* Hash function 1 */
        return (key % buckets);
    }
    
    int getBucketItems(int key) {
        /* Hash function 2 */
        return (key / bucketItems);
    }
    
    void add(int key) {
        int bucket = getBuckets(key);
        int bucketItem = getBucketItems(key);
        
        if(storage[bucket].empty()) {
            if (bucket == 0) {
                /* Special case for the 1 element of the array as space is from 0 to 999 */
                storage[bucket].resize(bucketItems+1,0);
            }
            else {
                storage[bucket].resize(bucketItems,0);
            }
        }
        storage[bucket][bucketItem] = true;
    }
    
    void remove(int key) {
        int bucket = getBuckets(key);
        int bucketItem = getBucketItems(key);
        
        if(storage[bucket].empty()) {
            return ;
        }
        else {
            storage[bucket][bucketItem] = false;
        }
    }
    
    bool contains(int key) {
        int bucket = getBuckets(key);
        int bucketItem = getBucketItems(key);
    
        if (storage[bucket].empty()) {
            return false;
        }
        else {
            return storage[bucket][bucketItem];
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
class MyHashSet {
    // bool storage [][]; Cant initialize this need to give the size of the nested array
    vector<vector<bool>> storage;
    int buckets;
    int bucketItems;
public:
    MyHashSet() {
        buckets=1000;
        bucketItems=1000;
        storage.resize(buckets,vector<bool>());
    }
    int getbucket(int key) {
        return (key % buckets);
    }
    int getbucketItem(int key) {
        return (key / bucketItems);
    }
    
    void add(int key) {
        int bucket = getbucket(key);
        int bucketItem = getbucketItem(key);
        
        if (storage[bucket].empty()) {
            if (bucket == 0) {
                storage[bucket].resize(bucketItems+1,0);
            }
            else {
                storage[bucket].resize(bucketItems,0);
            }
        }
        storage[bucket][bucketItem] = true; 
    }
    
    void remove(int key) {
        int bucket = getbucket(key);
        int bucketItem = getbucketItem(key);
        
        if (storage[bucket].empty()) {
            return ;
        }
        else {
            storage[bucket][bucketItem] = false;
        }
    }
    
    bool contains(int key) {
        int bucket = getbucket(key);
        int bucketItem = getbucketItem(key);
        if (storage[bucket].empty()) {
            return false;
        }
        return storage[bucket][bucketItem];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
class MyHashSet {
private:
    std::array<bool, 1000001> buckets;

public:

    MyHashSet() {buckets.fill(false);}
    
    void add(int key) {
        // could check, but writing a bit in a bit vector is easier
        buckets[key] = true;
    }
    
    void remove(int key) {
        buckets[key] = false;
    }
    
    bool contains(int key) {
        return buckets[key];
        
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
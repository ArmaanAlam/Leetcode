class MyHashSet {
    vector<int>hs;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        if(find(hs.begin(), hs.end(), key) == hs.end()){
            hs.push_back(key);
        }
    }
    
    void remove(int key) {
        auto it = find(hs.begin(), hs.end(), key);
        if(it != hs.end()){
            hs.erase(it);
        }
    }
    
    bool contains(int key) {
        return (find(hs.begin(), hs.end(), key) != hs.end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
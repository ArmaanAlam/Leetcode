class LRUCache {

    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*>mp;

    void addnode(Node *newNode){
        Node *temp = head->next;
        newNode->prev = head;
        newNode->next = temp;
        head->next = newNode;
        temp->prev = newNode;
    }


    void deletenode(Node *delnode){
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

public:

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }


    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node *resnode = mp[key];
            int value = resnode->val;

            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key] = head->next;

            return value;
        }
        return -1;
    }

    void put(int key, int value) {

        if(mp.find(key) != mp.end()){
            Node *presentnode = mp[key];
            deletenode(presentnode);
            mp.erase(key);
        }

        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
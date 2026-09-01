class MyLinkedList {

    class Node {
    public:
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = NULL;
        }
    };

    Node* head;
    Node* tail;
    int size;

public:
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return -1;
        }
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }

        return temp->data;
    }

    void addAtHead(int val) {
        if (size == 0) {
            head = new Node(val);
            tail = head;
        } else {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void addAtTail(int val) {
        if (size == 0) {
            head = new Node(val);
            tail = head;
        } else {
            Node* newNode = new Node(val);
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) {
            return;
        } 
        else if (index == 0) {
            addAtHead(val);
            return;
        } 
        else if (index == size) {
            addAtTail(val);
            return;
        } 
        else {
            Node* newNode = new Node(val);
            Node* temp = head;
            for (int i = 0; i < index - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            size++;
        }
    }

    void deleteAtIndex(int index) {

        if (index < 0 || index >= size) {
            return;
        }

        if(index == 0){
            Node* deletehead = head;
            head = head->next;
            delete deletehead;
            size--;

            if(size == 0){
                tail = NULL;
            }
            return;
        }
        else{

            Node *temp = head;
            for(int i = 0; i < index-1; i++){
                temp = temp->next;
            }

            Node *deleteNode = temp->next;

            if (deleteNode == tail) {
                tail = temp;
            }

            temp->next = deleteNode->next;
            deleteNode->next = NULL;

            delete deleteNode;
            size--;

        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
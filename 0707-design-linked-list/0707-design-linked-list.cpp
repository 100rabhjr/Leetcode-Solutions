class MyLinkedList {
    struct Node {
    int val;
    Node* next;

    Node(int x) {
        val = x;
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
            if (index < 0 || index >= size) return -1;
        
        Node* curr = head;
        for (int i = 0; i < index; ++i) {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
              Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        
        if (size == 0) {
            tail = newNode;
        }
        size++;  
    }
    
    void addAtTail(int val) {
         Node* newNode = new Node(val);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
             addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* curr = head;
        for(int i = 0;i < index-1;i++){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
          if (index < 0 || index >= size) return;
        
        Node* toDelete = NULL;
        
        if (index == 0) { 
            toDelete = head;
            head = head->next;
            if (size == 1) {
                tail = NULL;
            }
        } 
        else { 
            Node* curr = head;
         
            for (int i = 0; i < index - 1; ++i) {
                curr = curr->next;
            }
            
            toDelete = curr->next;
            curr->next = toDelete->next;
           
            if (index == size - 1) {
                tail = curr;
            }
        }
        
        delete toDelete;
        size--; 
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
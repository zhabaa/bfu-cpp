namespace ddl {
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    // void make(Node);
    void push_back(Node*, int);
    void push_front(Node*, int);
    void print(Node*);
    void clear(Node*);
    void remove(Node*);
    void duplicate(Node*);
    void bSort(Node*);

}

bool isPrime(int);
bool isEven(int);
bool isAllOdd(int);

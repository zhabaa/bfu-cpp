namespace linkedList {
    struct Node {
        int data;
        Node* next;
    };

    void make(Node *&head);

    void pushback(Node* head, int value);

    void print(Node* head);

    void pop(Node *head, int index);

    void clear(Node *head);

    void indexCopy(Node *head, int index);

    Node *get(Node *head, int index);

    Node *Check(Node *newnode, Node *sorted);

    Node *sort(Node *head);

    // void copy(Node *head, int x);
    // void Change(Node *head, int n);
    // void remove(Node *head, int x);
}

bool isEven(int n);
bool isAllDigitsEven(int number);
bool isGoodNumber(int x);
int CountDigits(int x);
int getFirstDigit(int x);

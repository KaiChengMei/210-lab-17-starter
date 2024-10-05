// COMSC-210 | Lab 17 | Kai-Cheng Mei
#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// add leverages functions
void addToFront(Node *&head, int value);
void addToTail(Node *&head, int value);
void deleteNode(Node *&head, int position);
void insertNode(Node *&head, int position, int value);
void deleteList(Node *&head);
void output(Node *head);

void output(Node *);

int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            addToFront(head, tmp_val) ;
        }
        else { // its a second or subsequent node; place at the head
            addToTail(head, tmp_val);
        }
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    cout<<"d";
    deleteNode(head, entry);
    output(head);

    // Insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000);  
    output(head);

    deleteList(head);
    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}



void addToFront(Node *&head, int value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

void addToTail(Node *&head, int value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(Node *&head, int position) {
    if (!head) return;  // If the list is empty

    Node *current = head;
    Node *prev = nullptr;
// if delete 1st node
    if (position == 1) {
        head = head->next;
        delete current;
        return;
    }

    for (int i = 1; i < position && current != nullptr; i++) {
        prev = current;
        current = current->next;
    }

    if (!current) return;
    prev->next = current->next;
    delete current;
}

// insert 10000 
void insertNode(Node *&head, int position, int value) {
    Node *newNode =  new Node;
    newNode->value =value;

    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *current = head;
    Node *prev =nullptr;

    for (int i = 1; i < position && current != nullptr;i++) {
        prev = current;
        current =current->next;
    }
}

// delete the entire linked list
void deleteList(Node *&head) {
    Node *current = head;
    while  (current) {
        Node *nextNode = current->next;
        delete current;
        current =nextNode;
    }
    head =nullptr;
}
